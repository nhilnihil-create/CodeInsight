#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int ctoi(char c) {return c-'0';}// char to int
int gcd(ll a,ll b){return b?gcd(b,a%b):a;}//MAX
int lcm(ll a,ll b){return a*b/gcd(a,b);}//MIN
 string s;
int  main(){
string ans ="AKIHABARA";

cin >> s;
  for(int i=0;i<9;i++){
    if(s[i]!=ans[i]) {
    s.insert(i,"A");
    }
  }
if(s==ans)cout<<"YES"<<endl;
else{
    cout << "NO"<<endl;
}
}
 
