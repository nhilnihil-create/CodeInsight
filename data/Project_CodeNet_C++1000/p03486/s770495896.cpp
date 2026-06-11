#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll gcd(ll x ,ll y){
    ll r = x%y;
    if(r==0)return y;
    else return gcd(y ,r);
}

int main(){
    string s,t;
    cin >> s >> t;
    vector<char> chs(s.size());
    vector<char> cht(t.size());
    for(int i=0;i<s.size();i++) chs[i] = s[i];
    for(int i=0;i<t.size();i++) cht[i] = t[i];
    sort(chs.begin() ,chs.end());
    sort(cht.begin() ,cht.end());
    reverse(cht.begin() ,cht.end());
    for(int i=0;i<s.size();i++) s[i] = chs[i];
    for(int i=0;i<t.size();i++) t[i] = cht[i];
    if(s<t)cout << "Yes" << endl;
    else cout << "No" << endl;
}