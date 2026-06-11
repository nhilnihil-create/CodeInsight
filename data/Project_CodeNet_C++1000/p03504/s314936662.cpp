#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_S =int(1e5) +5;
int broad[MAX_S][30];

int main(){
    ll N,C;
    cin  >> N >> C;

    int mt = 0;
    for(int i=0;i<N;i++){
        int s,t,c;
        cin >> s >> t >>c;
        c--;
        mt = max(mt,t);
        for(int j=s;j<=t;j++){
            broad[j][c]++;
        }
    }

    ll ans =0;
    for(int i=0;i<=mt;i++){
        ll temp=0;
        for(int j=0;j<C;j++){
            if(broad[i][j] >0){
                temp++;
            }
        }
        // cerr <<"i=" << i << "temp=" << temp << endl;
        ans =max(ans,temp);
    }
    cout << ans << endl;

    return 0;

}