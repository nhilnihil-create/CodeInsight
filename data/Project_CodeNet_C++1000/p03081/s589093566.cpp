/*
　　　  ∧＿∧　やあ
　　 （´・ω・｀)　　　　　/　　　　　ようこそ、バーボンハウスへ。
　　 ／∇y:::::＼　　　 [￣]　　　　　このテキーラはサービスだから、まず飲んで落ち着いて欲しい。
　　 |:⊃:|:::::|　　　|──|
￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣|　うん、「また」なんだ。済まない。
￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣|￣　  仏の顔もって言うしね、謝って許してもらおうとも思っていない。
￣￣￣￣￣￣￣￣￣￣￣￣￣￣／|
　　　　∇　∇　∇　∇　　　／.／|　　　でも、この提出を見たとき、君は、きっと言葉では言い表せない
　　　　┴　┴　┴　┴　／ ／　  |　　　「ときめき」みたいなものを感じてくれたと思う。
￣￣￣￣￣￣￣￣￣￣|／　　  |　　　殺伐としたコンテストの中で、そういう気持ちを忘れないで欲しい
￣￣￣￣￣￣￣￣￣￣　　　　 |　　　そう思って、この提出を投げたんだ。
　　　(⊆⊇)　(⊆⊇)　(⊆⊇)　　|
　    ||　　 ||　　||　　|　　　 じゃあ、判定を聞こうか。
　　.／|＼　／|＼ ／|＼
*/

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
#define fst first
#define snd second
#define ALL(obj) (obj).begin(),(obj).end()
#define debug(x) cerr << #x << " -> " << x << " (line:" << __LINE__ << ")" << '\n';
#define debugpair(x, y) cerr << "(" << #x << ", " << #y << ") -> (" << x << ", " << y << ") (line:" << __LINE__ << ")" << '\n';
typedef long long lint;
typedef priority_queue<int> p_que;
typedef priority_queue<int, vector<int>, greater<int>()> p_que_rev;
// const int INF = INT_MAX;
const lint LINF = LLONG_MAX;
const lint MOD = 1000000000 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);
const int di[]{0, -1, 0, 1, -1, -1, 1, 1};
const int dj[]{1, 0, -1, 0, 1, -1, -1, 1};

bool simulate(int start, int mode, string s, int n, int q, vector<char> &t, vector<char> &d){
  int pos = start;
  for (int i=0; i<q; ++i){
    if(s[pos] == t[i]){
      if(d[i] == 'L'){
        pos--;
      }
      else if(d[i] == 'R'){
        pos++;
      }
    }
    if(mode == 0 && pos < 0){
      return true;
    }
    else if(mode == 1 && pos >= n){
      return true;
    }
  }
  return false;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    lint n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<char> t(q);
    vector<char> d(q);
    for (int i=0; i<q; ++i){
      cin >> t[i] >> d[i];
    }
    int low = 0;
    int hi = n;
    int left = 0;
    int right = n;
    int mid;
    while(low != hi){
      mid = (low + hi) / 2;
      auto check = simulate(mid, 0, s, n, q, t, d);
      if(check){
        low = mid + 1;
      }
      else {
        hi = mid;
      }
    }
    left = low;
    // debug(left);
    low = 0;
    hi = n;
    while(low != hi){
      mid = (low + hi) / 2;
      auto check = simulate(mid, 1, s, n, q, t, d);
      // debugpair(mid, check);
      if(check){
        hi = mid;
      }
      else {
        low = mid + 1;
      }
    }
    right = low;
    // debug(right);
    lint ans = n;
    ans -= left;
    ans -= n - right;
    cout << ans << endl;
    return 0;
}