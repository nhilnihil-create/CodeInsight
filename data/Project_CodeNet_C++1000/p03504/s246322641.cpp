#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
using namespace std;


int main(){
   long long n, C;
   cin >> n >> C;
   vector<long long> s(n), t(n), c(n);
   for(int i = 0; i < n; ++i) cin >> s[i] >> t[i] >> c[i];
   vector<long long> cnt(1e5 * 2 + 2), sm(1e5 * 2 + 2);
   for(int i = 1; i <= C; ++i){
       cnt.assign(1e5 * 2 + 2, 0);
       for(int j = 0; j < n; ++j) if(c[j] == i) cnt[2 * s[j] - 2]++, cnt[2 * t[j]]--;
       for(int j = 1; j <= 1e5 * 2 + 1; ++j) cnt[j] += cnt[j - 1];
       for(int j = 0; j <= 1e5 * 2 + 1; ++j) if(cnt[j]) sm[j]++;
   }
   long long ans = 0;
   for(int i = 0; i <= 1e5 * 2 + 1; ++i) ans = max(ans, sm[i]);
   cout << ans;
}
