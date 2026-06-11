#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
typedef long long ll;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
#define INF 100000000
#define MAX_V 100001
#define MOD 1000000007
typedef vector<vector<int> > Graph;

int main(){
    int n;cin>>n;
    ll count=0;
    ll ans=0;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++){
        c[i]=a[i]-b[i];
        if(c[i]<0){
            ans++;
            count+=c[i];
        }
    }
    sort(c.begin(),c.end());
    for(int i=n-1;i>=0;i--){
        if(count>=0) break;
        if(c[i]<=0) break;
        count+=c[i];
        ans++;
    }
    if(count<0) cout<<-1<<endl;
    else cout<<ans<<endl;
}
