#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n;
int d[105];
int ans=1;;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    sort(d,d+n);
    for(int i=0;i<n-1;i++){
        if(d[i]!=d[i+1]) ans++;
    }
    cout<<ans<<endl;
    
}
