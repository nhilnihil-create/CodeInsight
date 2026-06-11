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
    bitset<2000*2000> bit;
    bit[0] = true;
    rep(i,0,N){
        bit |= bit << V[i];
    }
    int cnt = 0, sum = bit.count();
    rep(i,0,2000*2000){
        cnt += bit[i];
        if(cnt == sum / 2 + 1){
            cout << i << endl;
            return 0;
        }
    }
}