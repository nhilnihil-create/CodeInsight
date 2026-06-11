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

ll c[200010];

int main(void){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++)cin>>a[i];
    if(n==1&&a[0]!=0){
        cout<<-1<<endl;
        return 0;
    }
    for(ll i=0;i<n-1;i++){
        if(i==0&&a[0]!=0){
            cout<<-1<<endl;
            return 0;
        }
        if(a[i]+1<a[i+1]){
            cout<<-1<<endl;
            return 0;
        }
    }
    ll ans=0;
    for(ll i=1;i<n;i++){
        if(a[i-1]+1==a[i])ans++;
        else ans+=a[i];
    }
    cout<<ans<<endl;
    return 0;
}
