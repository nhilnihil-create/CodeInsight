#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int cnt[3];
    for(int i=0;i<3;i++) cnt[i]=0;
    for(int i=0;i<s.size();i++){
        cnt[s[i]-'a']++;
    }
    int ma=max({cnt[0],cnt[1],cnt[2]});
    if(ma<=cnt[0]+1 && ma<=cnt[1]+1 && ma<=cnt[2]+1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    return 0;
}