#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    string t;
    cin>>s>>t;
    map<char,set<char>>mps;
    map<char,set<char>>mpt;
    rep(i,s.size()){
        mps[s[i]].insert(t[i]);
        mpt[t[i]].insert(s[i]);
    }
    for(auto p: mps){
        if(p.second.size()>1){
            cout<<"No"<<endl;
            return 0;
        }
    }
    for(auto p: mpt){
        if(p.second.size()>1){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}