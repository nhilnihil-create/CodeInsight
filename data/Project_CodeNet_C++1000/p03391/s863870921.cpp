#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int N;
ll a,b;
ll sum,m=INF;

int main(){

  cin >> N;
  rep(i,0,N){
    cin >> a >> b;
    if(a > b){
      m = min(m,b);
    }
    sum += a;
  }
  sum -= m;
  if(m==INF) sum = 0;
  cout << sum << endl;

  return 0;
}
