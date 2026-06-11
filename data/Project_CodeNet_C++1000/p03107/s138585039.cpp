#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    string s;
    cin>>s;
    map<char,int> dict;
    rep(i,s.size()) dict[s[i]]++;
    int minv=100005;
    for(auto itr=dict.begin();itr!=dict.end();itr++){
        if(itr->second==s.size()) minv=0;
        else minv=min(minv,itr->second);
    }
    cout<<minv*2<<"\n";
    return 0;
}