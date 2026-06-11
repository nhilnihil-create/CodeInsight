#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    string s;
    cin>>s;
    int ans=0;
    int lg=0;
    while(lg+1<=s.size()){
        for(int i=0;i<s.size()-lg;i++){
            int tmp=0;
            rep(j,lg+1){
                if(s[i+j]=='A'||s[i+j]=='T'||s[i+j]=='G'||s[i+j]=='C'){
                    tmp++;
                }
            }
            if(tmp==lg+1) ans=max(ans,tmp);
        }
        lg++;
    }
    cout<<ans<<endl;
}