#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;


int main() {
 int64_t K,A,B;
 cin>>K>>A>>B;
 if(B-A<=2||K<=A-1){cout<<K+1<<endl;}
 else{
     int64_t ans=A+(K-(A-1))/2*(B-A)+(K-(A-1))%2;
     cout<<ans<<endl;
     }
 return 0;
}
