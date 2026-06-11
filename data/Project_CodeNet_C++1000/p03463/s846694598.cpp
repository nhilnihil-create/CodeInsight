#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int ctoi(char c) {return c-'0';}// char to int
int gcd(ll a,ll b){return b?gcd(b,a%b):a;}//MAX
int lcm(ll a,ll b){return a*b/gcd(a,b);}//MIN
 
int  main(){
int a,b,c;
cin >> a >> b >> c;
if((b+c)%2==0)cout<<"Alice"<<endl;
else cout<<"Borys"<<endl;
}
 
