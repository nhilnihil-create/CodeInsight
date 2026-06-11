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
    int n;cin>>n;
    vi a(n);
    rep(i,n){
        int x;cin>>x;
        a[i]=x;
    }
    if(a[0]!=0){
        cout<<-1<<endl;return 0;
    }
    reverse(been(a));
    int cur =a[0];
    ll ans =0;
    rep(i,n){
        if(a[i]+1<cur){
            cout<<-1<<endl;return 0;
        }
        else if(a[i]>=cur){
            cur=a[i];ans+=a[i];
        }
        else {
            cur=a[i];
        }
    }
    cout<<ans<<endl;
}