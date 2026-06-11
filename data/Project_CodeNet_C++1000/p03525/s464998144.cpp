#include <bits/stdc++.h>

using namespace std;

const unsigned long long MOD = 1000000007LL;
long long GCD(long long a, long long b){return b == 0 ? a : GCD(b, a % b);}
long long fast_exp(long long base, long long exp) {
    long long tot = 1;
    for(;exp > 0;exp >>= 1) {
       if((exp & 1) == 1) tot = tot * base % MOD;
       base = base * base % MOD;
    }
    return tot;
}

int cnt[15];
vector<int> times = {0};

int helper(int hour){

    if(hour == 13){

        int low = 30;

        //cout << "__________________________\n";

        for(int i = 0; i < times.size(); ++i){
            //cout << times[i] << " ";
            for(int j = i + 1; j < times.size(); ++j){
                int d = abs(times[i] - times[j]);
                low = min(low, min(d, 24 - d));
            }
        }

        //cout << endl << low << endl;

        return low;

    }

    if(cnt[hour] == 0) return helper(hour + 1);


    for(int i = 0; i < cnt[hour]; ++i)
        times.push_back(i % 2 == 0 ? 24 - hour : hour);

    int best = helper(hour + 1);

    for(int i = 0; i < cnt[hour]; ++i)
        times.pop_back();
    for(int i = 0; i < cnt[hour]; ++i)
        times.push_back(i % 2 == 1 ? 24 - hour : hour);


    best = max(best, helper(hour + 1));

    for(int i = 0; i < cnt[hour]; ++i)
        times.pop_back();

    return best;

}

int main(){

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;

    for(int i = 0; i < n; ++i){
        int j; cin >> j; ++cnt[j];
    }

    cout << helper(0);

    return 0;

}
