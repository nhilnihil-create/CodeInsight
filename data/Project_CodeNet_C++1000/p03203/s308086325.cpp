#include <bits/stdc++.h>

#define mp make_pair

using namespace std;

typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;
typedef pair<int,int> pii;
typedef pair<i64,int> pli;
typedef pair<int,i64> pil;
typedef pair<i64,i64> pll;
typedef vector<int> vi;
typedef vector<i64> vl;

template <typename T>
T id(T b) {return b;};
template <class It>
bool all(It f,It l){return std::all_of(f,l,id<bool>);}
template <class It>
bool any(It f,It l){return std::any_of(f,l,id<bool>);}

const int MAX_N = 200000;
int h,w,n;
pii xy[MAX_N];
pii yx[MAX_N];

int main()
{
  cin >> h >> w >> n;
  for (int i = 0; i < n; ++i) {
    cin >> xy[i].first >> xy[i].second;
    yx[i].first = xy[i].second;
    yx[i].second = xy[i].first;
  }

  sort(xy,xy+n);
  sort(yx,yx+n);
  int col = 1, row = 1, m = h;
  for (int i = 0; i < h; i++) {
    auto it = lower_bound(yx,yx+n,mp(col,row+1));
    if (it != yx+n && it->first == col)
      m = min(m, it->second-1);
    if (col < w && !binary_search(xy,xy+n,mp(row+1,col+1))) {
      col++;
    }
    if (row < h) row++;
  }

  cout << m << endl;

  return 0;
}
