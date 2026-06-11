#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;


int main() {
 int a,b;
 cin>>a>>b;
 if(a*b%2==0){cout<<"Even"<<endl;}
 else{cout<<"Odd"<<endl;}
 return 0;
}
