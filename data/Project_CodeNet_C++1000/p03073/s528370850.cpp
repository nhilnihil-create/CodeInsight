#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >>s;

    int mn=10000000;
    int n=s.length();
    int cnt=0;
    char ch;
    for(int i=0;i<n;i++){
        if(i&1)ch='0';
        else ch='1';
        if(s[i]!=ch)cnt++;
    }
    mn=min(mn,cnt);
    cnt=0;
    for(int i=0;i<n;i++){
        if(i&1)ch='1';
        else ch='0';
        if(s[i]!=ch)cnt++;
    }
    mn=min(mn,cnt);
    cout<<mn<<endl;
}

