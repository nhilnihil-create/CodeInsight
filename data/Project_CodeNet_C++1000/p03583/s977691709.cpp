#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;

int main() {
  int64_t N; cin>>N;
  bool finish=false;
  for(int i=1;i<3501;i++){
    for(int j=1;j<3501;j++){
      if((4*i*j-N*i-N*j)>0){
        if((N*i*j)%(4*i*j-N*i-N*j)==0){
          cout<<i<<' '<<j<<' '<<(N*i*j)/(4*i*j-N*i-N*j);
          finish=true;
          break;
        }
      }
    }
    if(finish) break;
  }  
}
