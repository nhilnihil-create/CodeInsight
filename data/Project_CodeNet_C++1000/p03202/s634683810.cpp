/// awoooooo

# include <bits/stdc++.h>
# define sz(x) (int)((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;

const int N = (int)2e5 + 5;
const int inf = (int)1e9 + 7;

int n;
int a[N];
set < int > pos;
map < int, int > val;


int ok(int x){
  pos.clear(), val.clear();
  for(int i = 2; i <= n; ++i){
    if(a[i] > a[i - 1]){
      continue;
    } else{
      while(!pos.empty() && *pos.rbegin() > a[i]){
        val.erase(*pos.rbegin());
        pos.erase(--pos.end());
      }
      for(int j = a[i]; j >= 1; --j){
        val[j]++;
        if(val[j] == x){
          if(x == 1) return 0;
          if(j == 1) return 0;
          val[j] = 0;
          pos.erase(j);
          val.erase(j);
        } else{
          pos.insert(j);
          break;
        }
      }
    }
  }
  return 1;
}

int main(){
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
  }
  int ans = n;
  for(int j = (1 << 20); j > 0; j >>= 1){
    if(ans > j && ok(ans - j)){
      ans -= j;
    }
  }
  printf("%d\n", ans);
  return 0;
}
