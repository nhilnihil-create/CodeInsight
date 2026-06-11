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
    int n,a,b,c; cin>>n>>a>>b>>c;
    int cd,bd,ad,ans=inf,m=1,cnt;
    vector<int> l(n,0);
    rep(i,n) cin>>l[i];
    rep(i,n) m*=4;
    rep(i,m){
        cnt=0;
        cd=0; bd=0; ad=0; 
        int p=i;
        rep(i,n){
            if(p%4==0){
                if(cd>0) cnt+=10;
                cd+=l[i];
            }
            else if(p%4==1){
                if(bd>0) cnt+=10;
                bd+=l[i];
            }
            else if(p%4==2){
                if(ad>0) cnt+=10;
                ad+=l[i];
            }
            p/=4;
        }
        cnt+=abs(cd-c)+abs(bd-b)+abs(ad-a);
        if(cd!=0 && bd!=0 && ad!=0)
        ans=min(ans,cnt);
    }
    cout<<ans<<endl;
}