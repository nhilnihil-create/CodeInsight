#include <bits/stdc++.h>
#define rep(i,n,m) for(int i=n;i<(int)(m);i++)
#define rrep(i,n,m) for(int i=((int)(n)-1);i>=m;i--)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<double> a(n);
    double avg;
    rep(i,0,n) {
        cin>>a[i];
        avg+=a[i];
    }
    avg/=n;
    
    double now=10000;
    int ans=0;
    rep(i,0,n){
        if(abs(a[i]-avg)<now){
            now=abs(a[i]-avg);
            ans=i;
        }
    }
    
    cout<<ans<<endl;
}
