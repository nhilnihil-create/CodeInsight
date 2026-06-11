#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;

int main() {
 string s;
 cin>>s;
 int count0=0,count1=0;
 for(int i=0;i<s.size();i++){
   if(s[i]=='0'){count0++;}
   else{count1++;}
 }
 cout<<min(count0,count1)*2<<endl;
return 0;
} 