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
    long long x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<long long> a(x), b(y), c(z);
    for(int i = 0; i < x; ++i)  cin >> a[i];
    for(int i = 0; i < y; ++i)  cin >> b[i];
    for(int i = 0; i < z; ++i)  cin >> c[i];

    vector<long long> ab;
    for(int i = 0; i < x; ++i)
       for(int j = 0; j < y; ++j)
              ab.push_back(a[i] + b[j]);
    sort(ab.rbegin(), ab.rend());
    sort(c.rbegin(), c.rend());
    vector<long long> ans;
    for(int i = 0; i < min(x * y, k); ++i)
        for(int j = 0; j < min(z, k); ++j)
            ans.push_back(ab[i] + c[j]);
    
    sort(ans.rbegin(), ans.rend());
    for(int i = 0; i < k; ++i) cout << ans[i]<< endl;
}