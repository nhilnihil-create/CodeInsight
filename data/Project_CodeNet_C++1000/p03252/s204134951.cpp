#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define ll long long

int main(){
    string s,t; cin >> s >> t;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    map<char,int> smp,tmp;
    map<int,int> sint,tint;
    rep(i,s.size()) smp[s[i]]++;
    rep(i,t.size()) tmp[t[i]]++;
    for(auto itr=smp.begin();itr!=smp.end();++itr){
        sint[itr->second]++;//登場回数がitr->second回の文字が何種類あるか何種類あるか
    }
    for(auto itr=tmp.begin();itr!=tmp.end();++itr){
        tint[itr->second]++;//登場回数がitr->second回の文字が何種類あるか何種類あるか
    }
    for(auto itr=sint.begin();itr!=sint.end();++itr){
        if(itr->second != tint[itr->first]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}