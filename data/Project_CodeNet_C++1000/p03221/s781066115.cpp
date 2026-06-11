#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int> 

int main(){
  int N, M; cin >> N >> M;
  int P[M], Y[M];
  vector<vector<int>> YM(100010);
  rep(i,M){
    cin >> P[i] >> Y[i];
    YM.at(P[i]).push_back(Y[i]);
  }

  rep(i,N+1) sort(all(YM.at(i)));

  rep(i,M){
    auto x = lower_bound(all(YM.at(P[i])),Y[i]) - YM[P[i]].begin();
    //cout << P[i] << " " << 1+int(x) << endl;
    //printf("%06d",P[i]);
    //printf("%06d",int(x)+1);
    //printf("\n");
    printf("%012lld\n",ll(P[i])*1000000+ll(x)+1);
  }

  return 0;
}