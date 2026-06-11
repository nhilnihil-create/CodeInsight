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

int main(){
    int d,g,ans=inf; cin>>d>>g;
    g/=100;
    vector<pp> q(d);
    rep(i,d){
        int p,c; cin>>p>>c;
        q[i]=mk(p,c/100);
    }
    rep(i,(1<<d)){
        int cnt=0,po=0;
        rep(j,d){
            if(i&(1<<j)){
                cnt+=q[j].first;
                po+=q[j].first*(j+1)+q[j].second;
            }
        }
        for(int j=d-1;j>=0;j--){
            if(po>=g) break;
            if(!(i&(1<<j))){
                if(g-po<=(q[j].first-1)*(j+1)){
                    cnt+=(g-po+j)/(j+1);
                    po=g;
                }
                else{
                    cnt+=q[j].first-1;
                    po+=(q[j].first-1)*(j+1);
                }
            }
        }
        if(po>=g) ans=min(ans,cnt);
    }
    cout<<ans<<endl;
}
