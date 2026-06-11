#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;


int main() {
 char N1,N2,N3,N4;
 cin>>N1>>N2>>N3>>N4;
 string t="";
 t+=N1;t+=N2;t+=N3;t+=N4;
 string d="1479";
 sort(t.begin(),t.end());
 if(t==d){
     cout<<"YES"<<endl;
 }
 else{cout<<"NO"<<endl;}
 return 0;
}