#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<math.h>
using namespace std;
#define mod (1000000000+7)
#define N (10007)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;

int main(void){
    ll n,a,b;
    cin>>n;
    vector<ll>s(n);
    ll ans=0;
    for(ll i=0;i<n;i++){
        cin>>a>>b;
        ans-=b;
        s[i]=a+b;
    }
    sort(s.begin(),s.end(),greater<ll>());
    for(ll i=0;i<n;i+=2)ans+=s[i];
    cout<<ans<<endl;
    return 0;
}