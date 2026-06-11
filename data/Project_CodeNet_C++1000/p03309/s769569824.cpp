#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#include <set>
using namespace std;
typedef long long ll;

int main(){
    int n;cin>>n;
    vector<ll> v(n),a(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        v[i]-=i+1;
    }
    sort(v.begin(),v.end());
    ll yay=v[n/2];
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=abs(v[i]-yay);
    }
    cout<<ans;
}