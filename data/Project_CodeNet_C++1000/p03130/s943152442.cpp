#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int ctoi(char c) {return c-'0';}// char to int
int gcd(ll a,ll b){return b?gcd(b,a%b):a;}//MAX
int lcm(ll a,ll b){return a*b/gcd(a,b);}//MIN
int  main(){
vector<int>a(4);
for(int i=0;i<6;i++){
    int z;
    cin >> z;
    a.at(z-1)++;
}
sort(a.begin(),a.end());
if(a.at(0)==1&&a.at(0)==a.at(1)&&a.at(2)==2&&a.at(2)==a.at(3))cout<<"YES"<<endl;
else cout <<"NO"<<endl;
}
 
