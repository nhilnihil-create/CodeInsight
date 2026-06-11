#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<climits>
#define MOD 1000000007
typedef long long ll;
using namespace std;

const int MAX = 200005;
int N,K;
ll modK[MAX];
int main(){
  cin >> N >> K;
  for(int i=1;i<=N;i++) modK[i%K]++;
  
  ll ans = 0;
  for(int a=0;a<K;a++){
    int b = (K-a)%K;
    int c = (K-a)%K;
    if((b+c)%K != 0) continue;
    ans += modK[a] * modK[b] * modK[c];
  }
  cout << ans << endl;
  return 0;
}