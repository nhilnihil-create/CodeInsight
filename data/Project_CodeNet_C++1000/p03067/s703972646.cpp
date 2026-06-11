#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;

int main() {
 int a,b,c;
 cin>>a>>b>>c;
 if(c>=min(a,b)&&c<=max(a,b)){cout<<"Yes"<<endl;}
 else{cout<<"No"<<endl;}
return 0;
} 