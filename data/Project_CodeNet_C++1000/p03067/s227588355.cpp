#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int ctoi(char c) {return c-'0';}// char to int
int gcd(ll a,ll b){return b?gcd(b,a%b):a;}//MAX
int lcm(ll a,ll b){return a*b/gcd(a,b);}//MIN
 
int  main(){
int a,b,c;
cin >> a >> b >> c;
vector<int>aa(3);
aa.at(0)=a;
aa.at(1)=b;
aa.at(2)=c;
sort(aa.begin(),aa.end());
if(aa.at(1)==c)cout<<"Yes"<<endl;
else cout<<"No"<<endl;
}
 
