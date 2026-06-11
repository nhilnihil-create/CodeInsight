#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
const ll MOD=1000000007;
const ll INF=1000000000000000001;
int main(){
 string s;cin>>s;
 int cnt=0;
 rep(i,s.size()-1){
    if(s[i]==s[i+1]){
        if(s[i]=='1')s[i+1]='0';
        if(s[i]=='0')s[i+1]='1';
        cnt++;
    }
 }
 cout << cnt << endl;
}