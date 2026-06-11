#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int N;
    cin >> N;
    vector<int> V(N);
    rep(i,0,N)cin >> V[i];
    int maxi = 0, second = INF;
    rep(i,0,N)maxi = max(maxi, V[i]);
    rep(i,0,N){
        if(abs(maxi/2 - second) > abs(maxi/2 - V[i])){
            second = V[i];
        }
    }
    for(int i = 0;maxi == second;i++)second = V[i];
    cout << maxi << " " << second << endl;
}