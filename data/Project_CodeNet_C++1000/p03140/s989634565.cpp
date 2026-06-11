#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int ctoi(char c) {return c-'0';}// char to int
int gcd(ll a,ll b){return b?gcd(b,a%b):a;}//MAX
int lcm(ll a,ll b){return a*b/gcd(a,b);}//MIN
 
int  main(){
int n;
cin >> n;
string a,b,c;
cin >> a >> b >> c;
int ans = 0;
for(int i=0;i<n;i++){
    char aa = a.at(i),bb=b.at(i),cc=c.at(i);
    if(aa==bb&&bb!=cc)ans++;
    if(bb==cc&&bb!=aa)ans++;
    if(aa==cc&&bb!=aa)ans++;
    if(aa!=bb&&bb!=cc&&cc!=aa)ans+=2;
}
cout << ans << endl;
}
 
