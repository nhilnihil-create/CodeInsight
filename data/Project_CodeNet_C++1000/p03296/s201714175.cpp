#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int ctoi(char c) {return c-'0';}// char to int
int gcd(ll a,ll b){return b?gcd(b,a%b):a;}//MAX
int lcm(ll a,ll b){return a*b/gcd(a,b);}//MIN
 
int  main(){
int n;
cin >> n;
vector<int>a(n);
int ans =0 ;
for(int i=0;i<n;i++)cin >> a.at(i);
int che =1;
for(int i=1;i<n;i++){
    if(a.at(i-1)==a.at(i))che++;
    else{
        ans+=che/2;
        che=1;
    }
    if(i==n-1)ans+=che/2;
}

cout<<ans<<endl;
}
 
