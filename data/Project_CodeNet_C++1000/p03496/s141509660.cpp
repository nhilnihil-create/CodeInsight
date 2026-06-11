#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define rrep(i,s,n) for(int i = (n)-1;i>=(s);i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define fi first
#define se second
#define chmin(a,b) a=min((a),(b))
#define chmax(a,b) a=max((a),(b))
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
typedef pair<pint,int> P1;
typedef pair<int,pint> P2;
typedef pair<pint,pint>PP;
static const ll maxLL = (ll)1 << 62;
const ll MOD=1000000007;
const ll INF=1e18;
int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};

int N;
int a[100010];

signed main(){
    cin.tie(0);
	ios::sync_with_stdio(false);
    cin>>N;
    int cnt1=0,cnt2=0;
    int icnt1,icnt2;
    rep(i,0,N){
        cin>>a[i];
        if(a[i]>cnt1 && a[i]>0){
            cnt1=a[i];
            icnt1=i;
        }else if(a[i]<cnt2 && a[i]<0){
            cnt2=a[i];
            icnt2=i;
        }
    }
    cout<<2*N-2<<endl;
    if(abs(cnt1)>abs(cnt2)){
        rep(i,0,N){
            if(i==icnt1)continue;
            a[i]+=cnt1;
            cout<<icnt1+1<<" "<<i+1<<endl;
        }
        rep(i,0,N-1){
            a[i+1]+=a[i];
            cout<<i+1<<" "<<i+2<<endl;
        }
    }else{
        rep(i,0,N){
            if(i==icnt2)continue;
            a[i]+=cnt2;
            cout<<icnt2+1<<" "<<i+1<<endl;
        }
        rrep(i,0,N-1){
            a[i+1]+=a[i];
            cout<<i+2<<" "<<i+1<<endl;
        }
    }
    
    
    //rep(i,0,N)cout<<a[i]<<endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}