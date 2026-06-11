#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;

int main(){
    fast_io

    char c[3][3];
    rep(i,3) rep(j,3) cin>>c[i][j];

    cout<<c[0][0]<<c[1][1]<<c[2][2]<<endl;

    return 0;

}
