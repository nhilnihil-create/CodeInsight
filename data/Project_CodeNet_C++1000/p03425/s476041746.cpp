#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;

int main() {
 int N;
 cin>>N;
 int64_t c[5]={0};
 for(int i=0;i<N;i++){
     string s;
     cin>>s;
     if(s[0]=='M'){c[0]++;}
     if(s[0]=='A'){c[1]++;}
     if(s[0]=='R'){c[2]++;}
     if(s[0]=='C'){c[3]++;}
     if(s[0]=='H'){c[4]++;}
 }
 int64_t ans=0;
  for(int i=0;i<5;i++){
   for(int j=i+1;j<5;j++){
    for(int k=j+1;k<5;k++){
     ans+=c[i]*c[j]*c[k];
     }
   }
  }
  cout<<ans<<endl;
 return 0;
}