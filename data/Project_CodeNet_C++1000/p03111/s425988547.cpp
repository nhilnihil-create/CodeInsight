#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define REP(i,n) for(ll i = 0;i < (ll)n;i++)
#define REPD(i,n) for(ll i = (ll)n - 1;i >= 0;i--)
#define ALL(x) (x).begin(),(x).end()
#define FILLl(n,first_dimension_size,value) fill((ll*)n,(ll*)(n+first_dimension_size),value)
#define FILL(n,first_dimension_size,value) fill((int*)n,(int*)(n+first_dimension_size),value)
#define INF (1 << 30)
#define MOD 1000000007
//int dy[4] = {-1,0,0,1};
//int dx[4] = {0,1,-1,0};


int main(){
  
  int n,a,b,c;
  cin >> n >> a >> b >> c;
  vector<int> l(n);
  REP(i,n)cin >> l[i];
  ll res = INF;
  for(int bita = 1;bita < (1 << n);bita++){
    vector<bool> usea(n,0);
    REP(i,n)if(bita >> i & 1)usea[i] = true;
    for(int bitb = 1;bitb < (1 << n);bitb++){
      vector<bool> useb(n,0);
      bool flag = true;
      REP(i,n){
        if(bitb >> i & 1){
          if(usea[i])flag = false;
          else useb[i] = true;
        }
      }
      if(!flag)continue;
      for(int bitc = 1;bitc < (1 << n);bitc++){
        flag = true;
        vector<bool> usec(n,0);
        ll sum = 0;
        REP(i,n){
          if(bitc >> i & 1){
            if(!usea[i] && !useb[i])usec[i] = true;
            else flag = false;
          }
        }
        if(!flag)continue;
        int aa = 0,bb = 0,cc = 0;
        int count = 0;
        REP(i,n)if(usea[i])aa += l[i],count++;
        if(count)sum += (count-1)*10;
        count = 0;
        REP(i,n)if(useb[i])bb += l[i],count++;
        if(count)sum += (count-1)*10;
        count = 0;
        REP(i,n)if(usec[i])cc += l[i],count++;
        if(count)sum += (count-1)*10;
        sum += abs(a-aa);
        sum += abs(b-bb);
        sum += abs(c-cc);
        res = min(res,sum);

      }
    }

  }
  cout << res << endl;



  return 0;
}