#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

int main(){
    int n;
    cin>>n;
    vector<ll> a(n),b(n),c(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    ll ans=0;
    for(int i=0;i<n;i++){
        auto atemp=lower_bound(a.begin(),a.end(),b[i]);
        auto ctemp=upper_bound(c.begin(),c.end(),b[i]);
        ans+=distance(a.begin(),atemp)*distance(ctemp,c.end());           
    }
    cout<<ans<<endl;
    return 0;
}