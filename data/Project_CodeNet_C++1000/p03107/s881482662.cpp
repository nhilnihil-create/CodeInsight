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
 vector<ll> cnt(2,0);
 rep(i,s.size()){
    cnt[s[i]-'0']++;
 }
 ll q=min(cnt[0],cnt[1]);
 cout << q*2 << endl;
 return 0;
}