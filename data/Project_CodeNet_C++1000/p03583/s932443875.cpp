#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

ll prime_factor(ll n) {
  map<ll, int > ret;
  ll MAX = 0;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      MAX=max(MAX,i);
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1){
    ret[n] = 1;
    MAX=max(MAX,n);
  }
  return MAX;
}

int main()
{
  int N;
  cin >> N;
  int flag=0;
  FOR(i,1,3501){
    FOR(j,1,3501){
      if((4*i*j-N*j-N*i)!=0&&(N*i*j)%(4*i*j-N*j-N*i)==0&&(N*i*j)/(4*i*j-N*j-N*i)>0){
        cout << (N*i*j)/(4*i*j-N*j-N*i) << " " << i << " " << j << endl;
        flag=1;
        break;
      }
    }
    if(flag==1){
      break;
    }
  }
  // if(N%2==0){
  //   cout << N << " " << N << " " << N/2 << endl;
  // }else if(N%3==0){
  //   cout << N/3 << " " << N*2 << " " <<  N*2 << endl;
  // }else{
  //   int flag = 0;
  //   ll x=prime_factor(N);
  //   for(ll k = x;k<=3501;k+=x){
  //     FOR(i,N/4,3501){
  //       FOR(j,N/4,3501){
  //         if(4*k*i*j==N*(k*i+i*j+j*k)){
  //           cout << k << " " << i << " " << j << endl;
  //           flag=1;
  //           break;
  //         }
  //       }
  //       if(flag==1){
  //         break;
  //       }
  //     }
  //     if(flag==1){
  //       break;
  //     }
  //   }
  // }
}