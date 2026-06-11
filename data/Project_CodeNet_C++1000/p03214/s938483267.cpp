#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int ctoi(char c) {return c-'0';}// char to int
int gcd(ll a,ll b){return b?gcd(b,a%b):a;}//MAX
int lcm(ll a,ll b){return a*b/gcd(a,b);}//MIN
 string s;
int  main(){
double  n;
cin >> n;
double  che = 0;
vector<double>a(n),b(n);
for(int i=0;i<n;i++){
    cin >> a.at(i);
    che+=a.at(i);
}
che/=n;
for(int i=0;i<n;i++){
    a.at(i)=abs(a.at(i)-che);
    b.at(i)=a.at(i);
}
sort(a.begin(),a.end());
for(int i=0;i<n;i++){
    if(b.at(i)==a.at(0)){
        cout << i << endl;
        break;
    }
}
}
 
