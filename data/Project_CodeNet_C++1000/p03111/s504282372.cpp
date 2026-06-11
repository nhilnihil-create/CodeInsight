#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> p;
long long N, A, B, C;
long long INF = 1e18;
vector<long long> l;
long long dfs(int i){
    long long ans = INF;
    if(i == N){
        long long res = 0;
        if(p[0].size() >= 1 && p[1].size() >= 1 && p[2].size() >= 1){
            res += (p[0].size() + p[1].size() + p[2].size() - 3) * 10;
            for(int j = 0; j < 3; j++){
                long long temp = 0;
                for(int k = 0; k < p[j].size(); k++){
                    temp += p[j][k];
                }
                if(j == 0) res += abs(temp - A);
                else if(j == 1) res += abs(temp - B);
                else if(j == 2) res += abs(temp - C);
            }
            return res;
        }
        else return INF;
    }
    for(int j = 0; j < 3; j++){
        p[j].push_back(l[i]);
        ans = min(dfs(i + 1), ans);
        p[j].pop_back();
    }
    ans = min(ans, dfs(i + 1));
    return ans;
}
int main(){
    cin >> N >> A >> B >> C;
    p.resize(3);//0がA1がB2がC
    l.resize(N);
    for(int i = 0; i < N; i++) cin >> l[i];
    cout << dfs(0) << endl;
}