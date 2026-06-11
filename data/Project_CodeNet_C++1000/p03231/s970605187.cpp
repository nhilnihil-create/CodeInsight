
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

long long gcd(long long a, long long b) { 
    if (a == 0)  {   return b;  }
    return gcd(b % a, a); 
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
        readll(n); readll(m);
        readstring(s1); readstring(s2);
        ll alpha = m/gcd(n,m), beta = n/gcd(n,m);
        bool isok = true;
        ll i = 0;
        while (i*alpha<s2.size() ) {
            isok = isok && (s1[i*beta]==s2[i*alpha]);
            ++i;
        }
        if (isok) {
            cout << (m*n)/gcd(m,n) << endl;
        } else {
            cout << -1 << endl;
        }

    }
 
//    auto end = chrono::steady_clock::now();
//    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;
 
    return 0;
}