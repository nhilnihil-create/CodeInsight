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
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        ll ai;
        cin>>ai;
        a[i]=ai-i-1;
    }
    sort(a.begin(),a.end());
    ll b=a[n/2];
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=abs(a[i]-b);
    }
    cout<<ans<<endl;
    return 0;
}