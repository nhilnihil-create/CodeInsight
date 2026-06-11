#include<bits/stdc++.h>

int main(){
    std::string s;
    std::cin>>s;
    std::string t;
    for(int i=0;i<s.size();++i){
        if(i+1<s.size()&&s[i]=='B'&&s[i+1]=='C'){
            t.push_back('D');
            i++;
        }
        else t.push_back(s[i]);
    }
    long long cnt=0,ans=0;
    for(int i=0;i<t.size();++i){
        if(t[i]=='A') cnt++;
        else if(t[i]=='D') ans+=cnt;
        else cnt=0;
    }
    std::cout<<ans<<'\n';
}
