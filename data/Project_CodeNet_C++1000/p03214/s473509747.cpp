#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n;
int a[105];
int s;
int m=1000000000;
int ans;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
    }
    for(int i=0;i<n;i++){
        if(abs(s-a[i]*n)<m){
            ans=i;
            m=abs(s-a[i]*n);
        }
    }
    cout<<ans<<endl;
    
}
