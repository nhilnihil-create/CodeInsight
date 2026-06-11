#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;

int main() {
 string s;
 cin>>s;
 for(int i=0;i<s.size();i++){
   for(int j=i;j<s.size();j++){
     for(int k=j;k<s.size();k++){
       if(s.substr(i,j)+s.substr(k)=="keyence"){
         cout<<"YES"<<endl;return 0;
       }
     }
   }
 }
 cout<<"NO"<<endl;
return 0;
} 