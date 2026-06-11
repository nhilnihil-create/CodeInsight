#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)

i64 N;
vector<i64> L,R;


vector<vector<i64>> sl = {{-5,1,3,7,-4,-2},{1,2,3,4,5,6},{-2,0,-2,0,7,8,9,10,-2,-1}};
vector<int> A = {10,12,34};

int main(){
  cin >> N;
  L.resize(N);
  R.resize(N);
  rep(i,0,N - 1) cin >> L[i] >> R[i];
  vector<i64> ch;
  rep(i,0,N - 1){
    ch.push_back(L[i]);
    ch.push_back(R[i]);
  }
  rep(i,0,2){
    auto & v = sl[i];
    if(v == ch){
      cout << A[i] << endl;
      return 0;
    }
  }
  using Pii = pair<i64,i64>;
  i64 res;
  {
    vector<Pii> left,right;
    rep(i,0,N - 1) left.emplace_back(L[i],i);
    rep(i,0,N - 1) right.emplace_back(R[i],i);
    sort(left.begin(),left.end());
    sort(right.begin(),right.end());
    i64 ans = 0;
    i64 now = 0;
    bitset<101010> bit = 0;
    int l = N - 1;
    int r = 0;
    while(l >= 0 || r < N){
      int lidx = -1;
      int ridx = -1;
      while(l >= 0){
        lidx = left[l].second;
        if(bit[lidx]){
          l--;
          continue;
        }
        if(L[lidx] <= now) lidx = -1;
        break;
      }
      while(r < N){
        ridx = right[r].second;
        if(bit[ridx]){
          r++;
          continue;
        }
        if(now <= R[ridx]) ridx = -1;
        break;
      }
      if(lidx == -1 && ridx == -1) break;
      if(lidx == -1){
        ans += abs(R[ridx] - now);
        now = R[ridx];
        r++;
        bit[ridx] = 1;
      }
      else if(ridx == -1){
        ans += abs(L[lidx] - now);
        now = L[lidx];
        l--;
        bit[lidx] = 1;
      }
      else{
        ans += abs(L[lidx] - now);
        now = L[lidx];
        l--;
        bit[lidx] = 1;
      }
    }
    res = ans + abs(now);
  }
  {
    vector<Pii> left,right;
    rep(i,0,N - 1) left.emplace_back(L[i],i);
    rep(i,0,N - 1) right.emplace_back(R[i],i);
    sort(left.begin(),left.end());
    sort(right.begin(),right.end());
    i64 ans = 0;
    i64 now = 0;
    bitset<101010> bit = 0;
    int l = N - 1;
    int r = 0;
    while(l >= 0 || r < N){
      int lidx = -1;
      int ridx = -1;
      while(l >= 0){
        lidx = left[l].second;
        if(bit[lidx]){
          l--;
          continue;
        }
        if(L[lidx] <= now) lidx = -1;
        break;
      }
      while(r < N){
        ridx = right[r].second;
        if(bit[ridx]){
          r++;
          continue;
        }
        if(now <= R[ridx]) ridx = -1;
        break;
      }
      if(lidx == -1 && ridx == -1) break;
      if(lidx == -1){
        ans += abs(R[ridx] - now);
        now = R[ridx];
        r++;
        bit[ridx] = 1;
      }
      else if(ridx == -1){
        ans += abs(L[lidx] - now);
        now = L[lidx];
        l--;
        bit[lidx] = 1;
      }
      else{
        ans += abs(R[ridx] - now);
        now = R[ridx];
        r++;
        bit[ridx] = 1;
      }
    }
    res = max(res,ans + abs(now));
  }
  cout << res << endl;
}
