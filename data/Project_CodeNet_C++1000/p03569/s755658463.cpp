#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    int l=0,r=n-1;
    int ans=0;
    while(1){
        if(s[l]!='x'&&s[r]!='x'){
            if(s[l]!=s[r]){
                cout<<-1<<endl;
                return 0;
            }
            else{
                r--; l++;
            }
        }
        if(s[l]=='x'&&s[r]!='x')l++,ans++;
        if(s[l]!='x'&&s[r]=='x')r--,ans++;
        if(s[l]=='x'&&s[r]=='x')r--,l++;
        if(r-l<=0)break;
    }
    cout<<ans<<endl;
}