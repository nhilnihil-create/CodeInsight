#include <bits/stdc++.h>
using namespace std;

// 0-indexed
// now node k
// child node k*2+1 and k*2+2
// parent node (k-1)/2
struct data {
  int a;
};
const int maxint = 2147483647;
data resetdata = {maxint};
struct RMQ {
  // except bottom size
  int sizen;
  vector<data> dat;
  RMQ(int newn = 1, data resets = resetdata) {
    reset(newn, resets);
  }
  void reset(int newn = 1, data resets = resetdata) {
    sizen = 1;
    while(sizen < newn) sizen *= 2;
    dat.resize(2 * sizen - 1);
    for(int i = 0; i < dat.size(); ++i) dat[i] = resets;
  }
  // "go up" process
  // data[k].a = newnum
  bool update(int k, int newnum) {
    k += sizen - 1;
    dat[k].a = newnum;
    while(k > 0) {
      k = (k - 1) / 2;
      dat[k].a = min(dat[k * 2 + 1].a, dat[k * 2 + 2].a);
    }
    return 1;
  }
  // "go down" process
  // return min number in [a,b)
  // pick(a,b,0,0,sizen)
  int pick(int a, int b, int k = 0, int l = 0, int r = -1) {
    if(r == -1) r = sizen;
    // [l,r)[a,b) or [a,b)[l,r)
    if(r <= a || b <= l) return maxint;
    // [a,[l,r),b)
    if(a <= l && r <= b) return dat[k].a;
    // else
    int nowl, nowr, nextlr = k * 2 + 1, med = (l + r) / 2;
    nowl = pick(a, b, nextlr, l, med);
    nowr = pick(a, b, nextlr + 1, med, r);
    return min(nowl, nowr);
  }
};

long long k;
vector<long long> v, sv, ans;
RMQ rmq;

long long calc(long long x) {
  long long ans = 0;
  while(x > 0) {
    ans += x % 10;
    x /= 10;
  }
  return ans;
}
bool asc(const long long l, const long long r) {
  long double lc = (long double)l / calc(l),
              rc = (long double)r / calc(r);
  if(lc != rc)
    return lc < rc;
  else
    return l < r;
}
void solve();

int main() {
  cin >> k;
  solve();
  for(int i = 0; i < k; ++i) cout << ans[i] << endl;
  return 0;
}

void solve() {
  long long ten = 1, nine = 0;
  while(1) {
    bool fin = 0;
    for(long long i = 1; i <= 150; ++i) {
      if(ten * i + nine > (long long)1e17) {
        fin = 1;
        break;
      }
      v.push_back(ten * i + nine);
      sv.push_back(ten * i + nine);
    }
    if(fin) break;
    nine *= 10;
    nine += 9;
    ten *= 10;
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  sort(sv.begin(), sv.end());
  sv.erase(unique(sv.begin(), sv.end()), sv.end());
  sort(sv.begin(), sv.end(), asc);
  rmq = RMQ(sv.size(), {1});
  for(int i = 0; i < sv.size(); ++i) {
    long long now = sv[i], id = 0;
    id = lower_bound(v.begin(), v.end(), now) - v.begin();
    if(id == 0 || rmq.pick(id, v.size())) {
      ans.push_back(now);
    }
    rmq.update(id, 0);
  }
}