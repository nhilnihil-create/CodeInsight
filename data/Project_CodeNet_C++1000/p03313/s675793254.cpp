
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <functional>
#include <queue>
#include <deque>
#include <stack>
#include <limits>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <fstream>
#include <iterator>
#include <random>
#include <chrono>
 
 
#define forr(i,start,count) for (int i = (start); i < (start)+(count); ++i)
#define set_map_includes(set, elt) (set.find((elt)) != set.end())
#define readint(i) int i; cin >> i
#define readll(i) ll i; cin >> i
#define readdouble(i) double i; cin >> i
#define readstring(s) string s; cin >> s
 
typedef long long ll;
 
using namespace std;

ll modd = 1000*1000*1000+7;

ll binary_search(function<bool(ll)> func, ll start, ll end) {
    /*      func:int ->bool
            returns smallest int x where func(x) evaluates to true, searches in [start,end), it is assumed the values are false, .. , false, true ...
             */
    if (end <= start) {   return end;  }   // has to be here, otherwise func(end-1) in next line could be a problem
    if (!func(end-1)) {  return end;  }
    while (end-start>1) {
        ll mid = (start+end)/2;
        if (func(mid)) {  end = mid;  } else { start = mid;   }
    }
    if (func(start)) {  return start;  } else {  return end;   }
};


template<class T>
T fastpower(T a, long long n) {  // n must be >= 1
  if (n==0) {return 1;}
  if (n % 2 == 0) {  
      T halfpower = fastpower<T>(a, n/2);
      return (halfpower*halfpower) % modd;
  } else {
      if (n == 1) {  return a; } else {  
          T halfpower = fastpower<T>(a, n/2);
          return (((halfpower*halfpower)%modd)*a)%modd;
      }
  }
};


int main()   {

    ios_base::sync_with_stdio(false);

    cout.precision(17);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> rand_gen(0, modd);   // rand_gen(rng) gets the rand no
 
//    auto start = chrono::steady_clock::now();
  
//    readint(test_cases);
    int test_cases = 1;
    forr(t, 1, test_cases) {
        readint(n);
        vector<int> a;
        forr(i,0,(1<<n)) {
            readint(kk); a.push_back(kk);
        }

        vector<pair<int,int>> max_a(1<<n), second_max_a(1<<n);
        max_a[0] = make_pair(a[0], 0);
        second_max_a[0] = make_pair(-1, -1);
        forr(i,1,(1<<n)-1) {
            set<pair<int,int>> candidates;
            candidates.insert(make_pair(a[i], i));
            forr(k,0,20) {
                if ((i & (1<<k)) != 0) {
                    candidates.insert(max_a[i - (1<<k)]);
                    candidates.insert(second_max_a[i - (1<<k)]);
                }
            }
            max_a[i] = *prev(candidates.end());
            second_max_a[i] = *prev(candidates.end(), 2);
        }

        int prev_answer = -1;
        forr(i,1,(1<<n)-1) {
            int new_answer = max_a[i].first + second_max_a[i].first;
            new_answer = max(new_answer, prev_answer);
            cout << new_answer << endl;
            prev_answer = new_answer;
        }

    }
 
//    auto end = chrono::steady_clock::now();
//    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;
 
    return 0;
}