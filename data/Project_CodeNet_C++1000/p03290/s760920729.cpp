#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using ULL = uint64_t;
const LL LLHUGE = numeric_limits<LL>::max() / 5; // for int64_t: 1.8 * 10^18
using P = pair<LL, LL>;
#define rep(i, n) for (LL i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
//#define DEBUG


// LL dfs(const LL depth, const LL d, const LL g,
//        const vector<LL> &p, const vector<LL> &c,
//        vector<LL> &completed) {
//   if (depth == d) {
//     LL cost = 0;
//     LL point = 0;
//     rep(i, d) {
//       // completed i
//       if (completed.at(i) == 1) {
//         point += (i + 1) * 100 * p.at(i) + c.at(i);
//         cost += p.at(i);
//       }
//     }
// //    cout << depth << " : " << cost << " : " << point << endl;
//     if (point >= g) {
//       return cost;
//     }
// //    cout << cost << endl;
//     for (int i = d - 1; i >= 0; --i) {
//       if (completed.at(i) == 0) {
//         if ((i + 1) * 100 * (p.at(i) - 1) < g - point) {
//           return HUGE; // infeasible
//         }
//         cost += (g - point) / ((i + 1) * 100);
//         cost += ((g - point) % ((i + 1) * 100) ? 1 : 0);
//         return cost;
//       }
//     }
//     abort(); // cannot happen
//   }
// 
//   LL min_cost = HUGE;
//   rep(i, 2) {
//     completed.at(depth) = i;
//     min_cost = min(min_cost, dfs(depth + 1, d, g, p, c, completed));
//   }
//   return min_cost;
// }

template <typename V>
void print_all(const V& v) {
  for (const auto e: v) {
    cout << e << "\t";
  }
  cout << endl;
}

int main() {
  LL d, g;
  cin >> d >> g;
  vector<LL> p(d, -1);
  vector<LL> c(d, -1);
  rep(i, d) {
    cin >> p.at(i) >> c.at(i);
  }
  
  vector<LL> priority(d, -1);
  iota(all(priority), (LL)0);

  LL n_problems_min = LLHUGE;
  do {
    LL n_problems = 0;
    LL pending_point = g;
    //print_all(priority);
    for (const auto i: priority) {
      // Solving i-th problem set:
      const LL this_problem_point = (i + 1) * 100;

      const LL this_point_sum = p.at(i) * this_problem_point + c.at(i);
      const LL this_point_sum_no_last = (p.at(i) - 1) * this_problem_point;
      if (pending_point > this_point_sum) {
        n_problems += p.at(i);
        pending_point -= this_point_sum;
      } else if (pending_point > this_point_sum_no_last) {
        n_problems += p.at(i);
        break;
      } else {
        n_problems += pending_point / this_problem_point;
        n_problems += pending_point % this_problem_point ? 1 : 0;
        break;
      }
    }
    n_problems_min = min(n_problems_min, n_problems);
  } while (next_permutation(all(priority)));

  
  cout << n_problems_min << endl;
  
  #ifdef DEBUG
  cout << "D: " << d << endl;
  cout << "G: " << g << endl;
  #endif
}

