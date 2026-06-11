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
        string s;
        cin>>s;
        
        int n=s.length();
        int mini=INT_MAX;
        int x;
        for(int i=0;i<=n-3;i++){
        	string ans;
            for(int j=i;j<i+3;j++){
                ans+=s[j];
                x=stoi(ans);
                x=abs(x-753);
                
            }
            // cout<<ans<<" ";
            // cout<<x<<endl;
            mini=min(x,mini);
        }
        cout<<mini<<endl;
    }   
    return 0;
}
