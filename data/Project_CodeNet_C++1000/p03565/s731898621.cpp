#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
using namespace std;

int main(){
string s,t,ans;
    int n=0;
    cin>>s>>t;
    ans="UNRESTORABLE";
    for(int i=s.size()-t.size();i>=0;i--){
        for(int j=0;j<=t.size();j++){
            if(j<t.size()&&t[j]!=s[i+j]&&s[i+j]!='?'){
                break;
            }
            else if(j==t.size()){
                n=i;
                ans=s;
            }
        }
        if(ans!="UNRESTORABLE"){
            break;
        }
    }    
    for(int i=n;i<n+t.size();i++){
       if(ans[i]=='?'){
           ans[i]=t[i-n];
       }
    }
    for(int i=0;i<s.size();i++){
       if(ans[i]=='?'){
           ans[i]='a';
       }
    }
    cout<<ans<<endl;
    return 0;
}
