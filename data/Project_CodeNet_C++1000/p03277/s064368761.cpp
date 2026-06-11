#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define trv(p, u) for (edg *p = h[u]; p; p = p->nxt)
#define push_back pb
typedef long long ll;
typedef double db;
const int N = 1e6 + 100;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

inline int rd() {
  int s = 0, w = 1; char c = getchar();
  while (c < '0' || c > '9') { if (c == '-') w = -1; c = getchar(); }
  while (c >= '0' && c <= '9') s = s * 10 + c - '0', c = getchar();
  return s * w;
}

int n, ans, a[N], s[N];

struct nod {
  int lft, rgt, sum;
  nod *ls, *rs;
  inline void setc() { sum++; }
  inline void upd() { sum = ls->sum + rs->sum; }
} pol[N << 2], *rot, *cur = pol;

inline void build(nod *r, int lft, int rgt) {
  r->lft = lft, r->rgt = rgt;
  if (lft == rgt) {
    r->sum = 0;
    return ;
  }
  int mid = (lft + rgt) >> 1;
  nod *ls = ++cur, *rs = ++cur;
  r->ls = ls, r->rs = rs;
  build(ls, lft, mid), build(rs, mid + 1, rgt);
  r->upd();
}

inline void chg(nod *r, int pos) {
  if (r->lft == pos && r->rgt == pos) {
    r->setc(); return ;
  }
  if (r->ls->rgt >= pos) chg(r->ls, pos);
  else chg(r->rs, pos);
  r->upd();
}

inline int qry(nod *r, int lft, int rgt) {
  if (lft > rgt) return 0;
  if (r->lft == lft && r->rgt == rgt) return r->sum;
  if (r->ls->rgt >= rgt) return qry(r->ls, lft, rgt);
  else if (r->rs->lft <= lft) return qry(r->rs, lft, rgt);
  else return qry(r->ls, lft, r->ls->rgt) +
              qry(r->rs, r->rs->lft, rgt);
}

inline bool chk(int x) {
  ll res = 0;
  memset(s, 0, sizeof(s));
  cur = pol;
  rep(i, 1, n) {
    if (a[i] <= x) s[i] = s[i - 1] + 1;
    else s[i] = s[i - 1] - 1;
  }
  rep(i, 0, n) s[i] += (n + 1);
  build(rot = pol, 1, N - 100);
  rep(i, 0, n) {
    res += 1ll * qry(rot, 1, s[i] - 1);
    chg(rot, s[i]);
  }
  return (res >= 1ll * n * (n + 1) / 4 + 1);
}

int main() {
  n = rd();
  rep(i, 1, n) a[i] = rd();
  int l = 1, r = inf;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (chk(mid)) ans = mid, r = mid - 1;
    else l = mid + 1;
  }
  printf("%d\n", ans);
  return 0;
}