#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1001001001;

int a[12][12];

int main() {
 int A,B,C,D,E;
 cin>>A>>B>>C>>D>>E;
 int ans=(A+9)/10*10+(B+9)/10*10+(C+9)/10*10+(D+9)/10*10+(E+9)/10*10;
 ans-=max({(A+9)/10*10-A,(B+9)/10*10-B,(C+9)/10*10-C,(D+9)/10*10-D,(E+9)/10*10-E});
 cout<<ans<<endl;
  return 0;
}