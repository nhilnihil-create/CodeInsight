#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;

int main(void){
    int n;
    cin>>n;
    int ans=0;
    int x[100],y[100];
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    for(int i=0;i<n;i++){
        cin>>y[i];
    }
    for(int i=0;i<n;i++){
        if(x[i]-y[i]>0){
            ans+=x[i]-y[i];
        }
    }
    cout<<ans<<endl;
}