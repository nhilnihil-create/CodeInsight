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
int a[N], ans;
map < int, int > cnt;

int main(){
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
    cnt[a[i]]++;
  }
  sort(a + 1, a + 1 + n);
  for(int i = n; i >= 1; --i){
    if(cnt[a[i]] == 0) continue;
    cnt[a[i]]--;
    int p = 0;
    while((1 << p) <= a[i]){
      ++p;
    }
    if(cnt[(1 << p) - a[i]]){
      ans++;
      cnt[(1 << p) - a[i]]--;
    }
  }
  printf("%d", ans);
  return 0;
}
