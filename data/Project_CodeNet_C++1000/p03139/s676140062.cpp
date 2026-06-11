#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int ctoi(char c) {return c-'0';}// char to int
int gcd(ll a,ll b){return b?gcd(b,a%b):a;}//MAX
int lcm(ll a,ll b){return a*b/gcd(a,b);}//MIN
 
int  main(){
int n,a,b;
cin >> n >> a >> b;
int che = a+b-n;
if(che<0)che=0;
cout << min(a,b)<<" "<<che<<endl;
}
 
