#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;

int main() {
	int R,G,B,N;
  cin>>R>>G>>B>>N;
  int cnt=0;
  for(int r=0;r<=3000;r++){
    for(int g=0;g<=3000;g++){
      if((N-r*R-g*G)%B==0&&(N-r*R-g*G)>=0){
       cnt++;
      }
    }
  }
  cout<<cnt<<endl;
  return 0;
}
