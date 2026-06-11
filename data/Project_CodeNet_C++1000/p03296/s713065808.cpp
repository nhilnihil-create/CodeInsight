/// awoooooo

# include <bits/stdc++.h>
# define sz(x) (int)((x).size())
# define X real()
# define Y imag()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef complex < ld > point;

const int N = (int)2e5 + 5;
const int inf = (int)1e9 + 7;

int n;
int a[N];

int main(){
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
  }
  int cnt = 1, res = 0;
  for(int i = 2; i <= n; ++i){
    if(a[i] != a[i - 1]){
      res += cnt / 2;
      cnt = 1;
    } else{
      ++cnt;
    }
  }
  res += cnt / 2;
  printf("%d\n", res);
  return 0;
}
