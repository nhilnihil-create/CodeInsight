#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;


int main() {
 string s;
 cin>>s;
 int countp=0,countm=0;
 for(int i=0;i<s.size();i++){
  if(s[i]=='+'){countp++;}
  else{countm++;}
 }
 cout<<countp-countm<<endl;
 return 0;
}
