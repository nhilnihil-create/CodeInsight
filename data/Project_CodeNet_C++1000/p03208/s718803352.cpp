#include <bits/stdc++.h>
using namespace std;


#define fast_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using lli = long long int;
using ll = long long ;
using ld=long double;
using d= double;

signed main(){
    fast_IO;
    int t=1;
    //cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<ll> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        ll d=INT_MAX;
        for(int i=0;i<=n-k;i++){
            if(a[i+k-1]-a[i]<d){
                d=a[i+k-1]-a[i];
            }
        }
        cout<<d<<endl;
    }   
    return 0;
}
