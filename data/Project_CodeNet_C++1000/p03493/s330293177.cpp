#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(void){
    string s; cin>>s;
    int ans=0;
    for(int i=0;i<3;i++){
        if(s[i]=='1'){
            ans++;
        }
    }
    cout<<ans<<endl;
    
}
