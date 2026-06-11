#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)4e6 + 9;
bitset<N> can;

int main(){
  fastIO;
  int n;
  cin >> n;
  int a;
  int s = 0;
  can[0]=1;
  for(int i = 0 ; i < n ; i ++ ){
    cin >> a;
    s += a;
    can = can | (can << a);
  }
  for(int j = (s+1)/2; j < N ; j ++ ){
    if(can[j]){
      cout << j;
      return 0;
    }
  }
  return 0;
}