#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    string t;
    cin>>s>>t;
    if(s.size()<t.size()){
        cout<<"UNRESTORABLE"<<endl;
        return 0;
    }
    int n=s.size();
    bool hon=false;
    int index=0;
    for(int i=0;i<=n-t.size();i++){
        bool ok=true;
        int cnt=0;
        if(s[i]=='?' || s[i]==t[0]){
            cnt+=1;
            for(int j=i;j<i+t.size();j++){
                if(s[j]!='?' && s[j]!=t[j-i]){
                    ok=false;
                    break;
                }
            }
        }
        if(cnt==0)ok=false;
        if(ok){
            hon=true;
            index=i;
        }
    }
    if(hon){
       string before=s.substr(0,index);
       int x=index+t.size();
       n-=x;
       string after=s.substr(index+t.size(),n);
       rep(h,before.size()){if(before[h]=='?')before[h]='a';}
       rep(k,after.size()){if(after[k]=='?')after[k]='a';}
       string ans=before;
       ans+=t;
       ans+=after;
       cout<<ans<<endl;
    }else cout<<"UNRESTORABLE"<<endl;
}