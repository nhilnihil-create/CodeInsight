#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int ctoi(char c) {return c-'0';}// char to int
int gcd(ll a,ll b){return b?gcd(b,a%b):a;}//MAX
int lcm(ll a,ll b){return a*b/gcd(a,b);}//MIN
 string s;
int  main(){
int n,a,b;
cin >> n >> a >> b;
int chea = 0,cheb=0,chec=0;
for(int i=0;i<n;i++){
    int z;
    cin >> z;
    if(z<=a)chea++;
    else if(z<=b)cheb++;
    else chec++;
}

cout << min({chea,cheb,chec})<< endl;
}
 
