#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;

int main() {
 int N;
 cin>>N;
 vector<string>u(N);
 vector<double>x(N);
 double ans=0;
 for(int i=0;i<N;i++){
     cin>>x[i]>>u[i];
     if(u[i]=="JPY"){ans+=x[i];}
     else{ans+=x[i]*380000;}
 }
 cout<<fixed<<setprecision(6);
 cout<<ans<<endl;

 return 0;
}
