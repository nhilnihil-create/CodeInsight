#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
int mod =1000000007;
const double PI = acos(-1);

int main(){
    vl ss,ns;
    rep(i,7) {
        ss.push_back(pow(6,i));
        ns.push_back(pow(9,i));
    }
    ll n;cin>>n;
    int ans =INF;
    rep(i,n+1){
        ll sp=i,np=n-i;
        int sum =0;
        ll sn=ss[6];
        while(sn>1){
            sum+=sp/sn;
            sp%=sn;
            sn/=6;
        }
        sum+=sp;
        
        ll nn=ns[6];
        while(nn>1){
            sum+=np/nn;
            np%=nn;
            nn/=9;
        }
        
        sum+=np;
        ans=min(ans,sum);
        
    }
    cout<<ans<<endl;
}