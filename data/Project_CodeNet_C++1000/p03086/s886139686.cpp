#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int ans;
int main(void){
    string s; cin>>s;
    for(int i=0;i<s.size();i++){
        for(int j=i;j<s.size();j++){
            bool x=true;
            for(int k=i;k<=j;k++){
                if(s[k]=='A'||s[k]=='T'||s[k]=='G'||s[k]=='C'){
                    
                }else{
                    x=false;
                }
            }
            if(x){
                ans=max(ans,j-i+1);
            }
        }
    }
    cout<<ans<<endl;

}

