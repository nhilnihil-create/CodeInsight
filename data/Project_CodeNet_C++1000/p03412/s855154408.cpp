#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define all(a) (a).begin(),(a).end()
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=10000000000000000;


int main(){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    rep(i,n){
        cin >> a.at(i);
    }
    rep(j,n){
        cin >> b.at(j);
    }
    ll ans=0;
    vector<int> aa(n),bb(n);
    rep(ii,29){
        int u=pow(2,ii),k=0;
        rep(i,n) aa.at(i)=a.at(i)%(u*2);
        rep(i,n) bb.at(i)=b.at(i)%(u*2);
        sort(bb.begin(),bb.end());
        rep(i,n){
            int s=lower_bound(all(bb),u-aa.at(i))-bb.begin();
            int f=lower_bound(all(bb),2*u-aa.at(i))-bb.begin();
            (k+=f-s+2)%=2;
            int ss=lower_bound(all(bb),3*u-aa.at(i))-bb.begin();
            int ff=lower_bound(all(bb),4*u-aa.at(i))-bb.begin();
            (k+=ff-ss+2)%=2;
            //cout << f << s << ff << ss << endl;
        }
        ans+=k*u;
    }
    cout << ans << endl;
}
