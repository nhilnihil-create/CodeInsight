#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
    
    
    ll n,a,b;
    cin>>n>>a>>b;
    if(a+b-1 > n || a*b<n){
        cout << -1 << endl;
        return 0;
    }
    while(n){
        int mi=min(a,n-(b-1));
        for(int i=n-mi+1;i<=n;i++)
        cout<<i<<' ';
        n-=mi;
        b--;
    }
}