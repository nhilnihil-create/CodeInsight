#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main(){
    string s,t; cin >> s >> t;
    int len = max(s.size(), t.size());
    vector<int> S(int(s.size()),0);
    vector<int> T(int(t.size()),0);
    for(int i=0;i<len;i++){
        if(i<s.size()) S[i] = s[i]-'a'+1;
        if(i<t.size()) T[i] = t[i]-'a'+1;
    }
    sort(S.begin(), S.end());
    sort(T.begin(), T.end());
    reverse(T.begin(), T.end());

    for(int i=0;i<len;i++){
        if(i>=s.size()){
            if(i<t.size()) {cout << "Yes" << endl; break;}
            else {cout << "No" << endl; break;}
        } else if (i>=t.size()){
            cout << "No" << endl;
        }else{
            if(S[i] == T[i]) {
                if(i==len-1) cout << "No"<< endl;
                continue;
            }
            if(S[i] > T[i]) {cout << "No" << endl; break;}
            if(S[i] < T[i]) {cout << "Yes" << endl;break;}
        }
    }

}
