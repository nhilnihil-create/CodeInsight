#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;

typedef long long ll;
ll INF = 1LL << 60;
ll MAX = 100010;
ll MOD = 2019;

int
main() 
{
  int N; cin >> N;
  int M; cin >> M;
  vector<vector<int>> arr(N + 1);
  vector<int> original(N);
  int city[M];
  int id[M];
  rep(i, 0, M){
    int P, Y;
    cin >> P >> Y;
    city[i] = P;
    id[i] = Y;
    arr[P].push_back(Y);
  }
  
  repe(i, 1, N){
    sort(arr[i].begin(), arr[i].end());
  }

  rep(i, 0, M){
      printf("%06d", city[i]);
      printf("%06d\n", 1 + lower_bound(arr[city[i]].begin(), arr[city[i]].end(),id[i]) - arr[city[i]].begin());
}

}

