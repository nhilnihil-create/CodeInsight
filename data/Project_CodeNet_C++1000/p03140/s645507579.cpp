#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n;
string a,b,c;
int ans;
int main(void){
    cin>>n>>a>>b>>c;
    for(int i=0;i<n;i++){
        if(a[i]==b[i]&&b[i]==c[i]){
            
        }else if(a[i]==b[i]){
            ans++;
        }else if(b[i]==c[i]){
            ans++;
        }else if(a[i]==c[i]){
            ans++;
        }else{
            ans+=2;
        }
    }
    cout<<ans<<endl;
    
}
