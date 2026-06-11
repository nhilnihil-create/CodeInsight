//
// Created by yamunaku on 2019/08/30.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD1 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> mti;
typedef vector<ll> vl;
typedef vector<vector<ll>> mtl;

int main(){
    int n;
    ll aa;
    cin >> n >> aa;
    vl a(n);
    rep(i,n) cin >> a[i];
    ll ans=LINF;
    vl rui(n+1);
    rui[0]=0;
    repl(i,1,n+1) rui[i]=rui[i-1]+a[i-1];
    int s=1;
    if(n>2000) s=10;
    repl(i,s,n+1){
        ll tmp=aa*i+2*(rui[n]-rui[n-i]);
        int k=1;
        for(int j=n;j>0;j-=i){
            tmp+=(rui[j]-rui[max(j-i,0)])*(2*k+1);
            k++;
        }
        ans=min(ans,tmp);
    }
    cout << ans+aa*n << endl;
    return 0;
}
