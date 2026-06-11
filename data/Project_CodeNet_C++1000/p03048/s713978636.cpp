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
 for(int i=0;i<=N/R;i++){
	 for(int j=0;j<=(N-i*R)/G;j++){
		 if((N-i*R-j*G)%B==0){cnt++;}
		 }
	 }
 
 cout<<cnt<<endl;
  return 0;
}
