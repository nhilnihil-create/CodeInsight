#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;


int main() {
 int N1,N2,N3,N4;
 cin>>N1>>N2>>N3>>N4;
 vector<int>k(100);
 k[N1]++;
 k[N2]++;
 k[N3]++;
 k[N4]++;
 if(k[1]==1&&k[9]==1&&k[7]==1&&k[4]==1){
     cout<<"YES"<<endl;
 }
 else{cout<<"NO"<<endl;}
 return 0;
}