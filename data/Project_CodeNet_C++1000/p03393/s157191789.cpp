//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

int main(){
    string s; cin>>s;
    map<char,ll>mp;
    rep(i,s.size()){
        mp[s[i]]++;
    }
    for(char c='a';c<='z';c++){
        if(mp[c]>=1)continue;
        s+=c;
        cout<<s<<endl;
        return 0;
    }
    if(s=="zyxwvutsrqponmlkjihgfedcba"){
        cout<<-1<<endl;
        return 0;
    }
    int change;
    for(int i=s.size()-1;0<i;i--){
        if(s[i-1]>s[i])continue;
        change=i-1;
        break;
    }
    //cout<<s[change]<<endl;
    char mn='z';
    char kaeru=s[change];
    for(int i=change+1;i<s.size();i++){
        if(s[i]<=kaeru)continue;
        mn=min(mn,s[i]);
    }
    string ans=s.substr(0,change);
    ans+=mn;
    cout<<ans<<endl;
}

















































