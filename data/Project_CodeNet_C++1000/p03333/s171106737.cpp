#include <bits/stdc++.h>
#define F first
#define S second
#define int long long
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

int Calc(int l,int r,int pos) {
  if (l <= pos && pos <= r) {
    return 0;
  } else if (pos < l) {
    return l - pos;
  } else {
    return r - pos;
  }
}

signed main() {
  int N;
  cin >> N;
  ll ans = 0;
  vector<P> seg(N);
  vector<P> l(N);
  vector<P> r(N);
  bool used[N];
  for (int i = 0; i < N; i++) {
    cin >> seg[i].F >> seg[i].S;
    used[i] = false;
    l[i].F = seg[i].F; l[i].S = i;
    r[i].F = seg[i].S; r[i].S = i; 
  }
  sort(l.begin(),l.end());
  reverse(l.begin(),l.end());
  sort(r.begin(),r.end());

  int pos = 0;
  int lpos = 0;
  int rpos = 0;
  int turn = 0;
  while (lpos != N && rpos != N) {
    if (turn % 2 == 0) {
      if (used[l[lpos].S]) {
        lpos++;
      } else {
        ans += abs(Calc(seg[l[lpos].S].F,seg[l[lpos].S].S,pos));
        used[l[lpos].S] = true;
        pos += Calc(seg[l[lpos].S].F,seg[l[lpos].S].S,pos);
        turn++;  lpos++;
      }
    } else {
      if (used[r[rpos].S]) {
        rpos++;
      } else {
        ans += abs(Calc(seg[r[rpos].S].F,seg[r[rpos].S].S,pos));
        used[r[rpos].S] = true;
        pos += Calc(seg[r[rpos].S].F,seg[r[rpos].S].S,pos);
        turn++; rpos++;
      }
    }
  }

  ans += abs(pos);
  ll res1 = ans;

  pos = 0;
  lpos = 0;
  rpos = 0;
  turn = 0;
  ans = 0;
  for (int i = 0; i < N; i++) used[i] = false;

  while (lpos != N && rpos != N) {
    if (turn % 2 == 1) {
      if (used[l[lpos].S]) {
        lpos++;
      } else {
        ans += abs(Calc(seg[l[lpos].S].F,seg[l[lpos].S].S,pos));
        used[l[lpos].S] = true;
        pos += Calc(seg[l[lpos].S].F,seg[l[lpos].S].S,pos);
        turn++;  lpos++;
      }
    } else {
      if (used[r[rpos].S]) {
        rpos++;
      } else {
        ans += abs(Calc(seg[r[rpos].S].F,seg[r[rpos].S].S,pos));
        used[r[rpos].S] = true;
        pos += Calc(seg[r[rpos].S].F,seg[r[rpos].S].S,pos);
        turn++; rpos++;
      }
    }
  }
  ans += abs(pos);
  ll res2 = ans;
  
  cout << max(res1,res2) << endl;
  return 0;
}