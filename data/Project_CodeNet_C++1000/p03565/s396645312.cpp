#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s,t;
    cin>>s>>t;
    int n=s.length();
    int m=t.length();
    string ans="UNRESTORABLE";
    for(int i=0;i<=n-m;i++){
        bool flag=true;
        string u=s;
        for(int j=0;j<m;j++){
            if(s[i+j]!=t[j]&&s[i+j]!='?') flag=false;
            u[i+j]=t[j];
        }
        if(flag){
            replace(u.begin(),u.end(),'?','a');
            ans=u;
        }
    }
    cout<<ans<<endl;
}