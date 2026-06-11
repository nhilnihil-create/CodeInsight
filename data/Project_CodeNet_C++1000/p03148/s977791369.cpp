#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>

#define rep(i, a, b) for ( long long  i = (a); i < (b); i++ )
#define per(i, a, b) for ( long long i = (b)-1; i >= (a); i--)
#define pb push_back
#define bg begin()
#define en end()
#define DEBUG_INT(var) printf("the value of "#var" is %d\n", var)
#define PRINT_ARRAY(name, i) printf("the value of "#name"[%d] is %d\n", (i), name[(i)])
#define DEBUG_ARRAY(name, begin, end) REP(i, begin, end) PRINT_ARRAY(name, i)

#define pr_arr(name, a, b) \
  for (int i = (a); i < (b); i++) { \
    for (int j = (a); j < (b); j++) {\
      if (j > (a)) printf(" "); \
      printf("%lld", name[i][j]); \
    }\
    printf("\n");\
  }\

#define YES puts("YES")
#define NO  puts("NO")
#define Yes puts("Yes")
#define No  puts("No")

using namespace std;

typedef long long ll;

struct Sushi {
  ll t, d;
  
  bool operator< (const Sushi &s) const {
    return d < s.d;
  }
    bool operator> (const Sushi &s) const {
    return d > s.d;
  }
};

ll N, K, sum;
priority_queue<Sushi, vector<Sushi>, greater<Sushi> > S; //K個で同じ種類数のうち、最大の集合
priority_queue<Sushi> T;
map<ll, int> m;
vector<ll> ans;


int main(void) {
    scanf("%lld %lld", &N, &K);
    rep(i, 0, N) {
      Sushi s;
      scanf("%lld %lld", &s.t, &s.d);
      
      T.push(s);
    }
    
    ll num = 0; //S内のネタの種類数
    rep(i, 0, K) {
      Sushi t = T.top(); T.pop();
      if(m[t.t] == 0) {
        num++;
      }
      m[t.t]++;
      sum += t.d;
      S.push(t);
    }
    
    sum += num*num;
    ans.pb(sum);
    
    //S内の種類数がKになるか、TにSと同じ種類しか残されていないか、Tが空になるまで続ける
    while (num<K && !T.empty() && !S.empty()) {
      // TからSとネタが重複しないもののうち、最大おいしさのすしを選ぶ
      Sushi t = T.top(); T.pop();
      while(m[t.t] >= 1 && !T.empty()) {
        t = T.top(); T.pop();
      }
      if (m[t.t] >= 1) break;
      
      //Sから重複しているもののうち、最大おいしさの寿司を取り除く
      //空なら無視
      Sushi s = S.top(); S.pop();
      while (m[s.t] <= 1 && !S.empty()) {
        s = S.top(); S.pop();
      }
      if (m[s.t] <= 1) break;
      
      num += 1;
      if (m[s.t] >= 2) m[s.t]--;
      m[t.t]++;
      sum = sum - s.d + t.d + 2 * num - 1;
      ans.pb(sum);
      //printf("%lld\n", sum);
      
    }
    sort(ans.bg, ans.en, greater<ll>());
    
    
  
    printf("%lld\n", ans[0]);
    return 0;
}
