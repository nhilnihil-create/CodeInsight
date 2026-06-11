#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)     for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = m; i < (int)(n); i++)
#define MOD 1000000007
#define Graph vector<vector<int>>
#define lint int64_t

int main(){
    int N;
    cin >> N;

    vector<int> Ai;
    double sum = 0.0;
    rep(i,N){
       int ai;
       cin >> ai;
       Ai.push_back(ai);
       sum += ai;
    }

    double ave = sum / N;
    int ans = 0;
    double min = abs(Ai.at(0) - ave);

    rep(i,N){
       double diff = abs(Ai.at(i) - ave);
       if(min > diff){
         ans = i;
         min = diff;
       }
    }

    cout << ans << endl;
    return 0;
}
