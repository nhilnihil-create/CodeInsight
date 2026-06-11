#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;

int main() {
 int64_t N,A,B,C,D,E;
 cin>>N>>A>>B>>C>>D>>E;
 int64_t a=min({A,B,C,D,E});
 cout<<(N+a-1)/a+4<<endl;
return 0;
} 