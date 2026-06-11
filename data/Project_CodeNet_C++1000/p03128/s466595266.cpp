#include <bits/stdc++.h>
using namespace std;

const map<int, int> g_num_matches = {
    {1, 2},
    {2, 5},
    {3, 5},
    {4, 4},
    {5, 5},
    {6, 6},
    {7, 3},
    {8, 7},
    {9, 6},
};

bool compare(const array<int, 6>& a, const array<int, 6>& b, vector<int> order){
    int na = 0;
    int nb = 0;
    for(auto& n : a) na += n;
    for(auto& n : b) nb += n;
    if     (na > nb) return true;
    else if(na < nb) return false;
    for(auto i : order){
        if     (a[i] == b[i]) continue;
        else if(a[i] > b[i]) return true;
        else                 return false;
    }
    return false;
}

int main()
{
    int N, M;
    cin >> N >> M;
    int Ai;
    vector<int> useNum(6, 0);
    for(int i=0;i<M;i++){
        cin >> Ai;
        auto n = g_num_matches.at(Ai) - 2;
        useNum[n] = max(useNum[n], Ai);
    }

    map<int, int> orderm;
    for(int i=0; i<6; i++){
        if(useNum[i] == 0) continue;
        orderm[-useNum[i]] = i;
    }
    vector<int> order;
    for(auto& m : orderm) order.push_back(m.second);

    vector<int> dp(N+1, -1);
    dp[0] = 0;
    vector<array<int, 6>> nums(N+1, array<int, 6>{0, 0, 0, 0, 0, 0});
    for(int i=0; i<=N; i++){
        for(int j=0; j<6; j++){
            if(useNum[j] == 0) continue;
            auto k = i-(j+2);
            if(k < 0) continue;
            if(dp[k] < 0) continue;
            if(dp[i] <= 1 + dp[k]){
                dp[i] = 1 + dp[k];
                auto nums_new = nums[k];
                nums_new[j]++;
                if(compare(nums_new, nums[i], order)){
                    nums[i] = nums_new;
                }
            }
        }
    }

    string S;
    for(auto i : order){
        S += string(nums[N][i], '0' + useNum[i]);
    }
    cout << S << endl;

    return 0;
}
