#include <fstream>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  ulong a[200000];
  cin >> n;

  uint l;
  ulong tmp_sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> l;
    tmp_sum += l;
    a[i] = tmp_sum;
  }

  ulong val = ULONG_MAX, tmp_max, tmp_min;
  int l_pos = 0, r_pos = 2;
  ulong ll_val, lr_val, rl_val, rr_val;
  ulong p,q,r,s;
  for (int c_pos = 1; c_pos < n-2; c_pos++)
  {
    ulong l_diff = ULONG_MAX, r_diff = ULONG_MAX;
    while (1)
    {
      ll_val = a[l_pos];
      lr_val = a[c_pos] - a[l_pos];
      ulong tmp_l_diff = max(ll_val,lr_val) - min(ll_val,lr_val);
      if (tmp_l_diff < l_diff)
      {
        l_diff = tmp_l_diff;
      }
      else
      {
        l_pos--;
        break;
      }
      l_pos++;
    }
    if (r_pos == c_pos) r_pos++;
    while (1)
    {
      rl_val = a[r_pos] - a[c_pos];
      rr_val = a[n-1] - a[r_pos];
      ulong tmp_r_diff = max(rl_val,rr_val) - min(rl_val,rr_val);
      if (tmp_r_diff < r_diff)
      {
        r_diff = tmp_r_diff;
      }
      else
      {
        r_pos--;
        break;
      }
      r_pos++;
    }
    p = a[l_pos];
    q = a[c_pos] - a[l_pos];
    r = a[r_pos] - a[c_pos];
    s = a[n-1] - a[r_pos];
    tmp_max = max(p,max(q,max(r,s)));
    tmp_min = min(p,min(q,min(r,s)));
    if (val > tmp_max - tmp_min) val = tmp_max - tmp_min;
  }

  cout << val << "\n";

}
