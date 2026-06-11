#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;


int main() {
  vector<char>t(4);
  for(int i=0;i<4;i++){
    cin>>t[i];
  }
  for(int s=0;s<(1<<3);s++){
    string q;q+=t[0];
    int sum=t[0]-'0';
    for(int i=0;i<3;i++){
      if((s>>i)&1){sum+=t[i+1]-'0';q+='+';q+=t[i+1];}
      else{sum-=t[i+1]-'0';q+='-';q+=t[i+1];}
    }
    if(sum==7){cout<<q<<"=7"<<endl;return 0;}
  }
  return 0;  
}