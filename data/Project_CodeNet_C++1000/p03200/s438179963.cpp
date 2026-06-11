#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;

int main() {
 string s;
 cin>>s;
 reverse(s.begin(),s.end());
 int w=s.size()+1;
 for(int i=0;i<s.size();i++){
     if(s[i]=='W'){w=i;break;}
 }
 int64_t ans=0;
 for(int i=0;i<s.size();i++){
     if(i>w&&s[i]=='B'){ans+=(i-w);w++;}
 }
 cout<<ans<<endl;
 return 0;
}