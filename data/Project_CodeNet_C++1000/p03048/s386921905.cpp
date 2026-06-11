//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main() {
    int r,g,b,n,ans=0; cin>>r>>g>>b>>n;
    rep(i,n+1){
        rep(j,n+1){
            int num=n-i*r-j*g;
            if(0<=num && num%b==0) ans++;
        }
    } 
    cout<<ans<<endl;
}