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
#include <climits>
using namespace std;


int main(){
    long long n, k;
    cin >> n >> k;
    vector<pair<long long, long long> > a(n);
    for(int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
    long long ans = LLONG_MAX;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            for(int l = 0; l < n; ++l)
                for(int m = 0; m < n; ++m){
                    long long x1 = a[i].first, x2 = a[j].first, y1 = a[l].second, y2 = a[m].second;
                    if(x1 > x2) swap(x1, x2);
                    if(y1 > y2) swap(y1, y2);
                    long long cnt = 0;
                    for(int MORE = 0; MORE < n; ++MORE){
                        if(a[MORE].first >= x1 && a[MORE].first <= x2){
                            if(a[MORE].second >= y1 && a[MORE].second <= y2) cnt++;
                        }
                    }
                    if(cnt >= k){
                        long long s = (x2 - x1) * (y2 - y1);
                        ans = min(ans, s);
                    }
                }
    cout << ans;
}
