#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int ctoi(char c) {return c-'0';}// char to int
int gcd(ll a,ll b){return b?gcd(b,a%b):a;}//MAX
int lcm(ll a,ll b){return a*b/gcd(a,b);}//MIN
 
int  main(){
int n;
string s;
cin >> n >> s;
int ans = 0;
for(int i=0;i<n;i++){
    if(s.at(i)=='R')ans++;
    else ans--;
}
if(ans>0)cout<<"Yes"<<endl;
else cout<<"No"<<endl;
}
 
