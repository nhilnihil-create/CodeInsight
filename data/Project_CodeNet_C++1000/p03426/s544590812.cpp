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

vector<pair<long long, long long> > a;

int main(){
    long long h, w, d;
    cin >> h >> w >> d;
    a.resize(h * w + 1);
    for(int i = 1; i <= h; ++i)
        for(int j = 1; j <= w; ++j){
            long long c;
            cin >> c;
            a[c] = make_pair(i, j);
        }
    vector<long long> ans(h * w + 1);
    for(int i = 1; i <= h * w; ++i){
        if(i - d <= 0) continue;
        ans[i] = abs(a[i - d].first - a[i].first) + abs(a[i - d].second - a[i].second) + ans[i - d];
    }
    long long t, l, r;
    cin >> t;
    for(int i = 0; i < t; ++i){
        cin >> l >> r;
        cout << ans[r] - ans[l] << endl;
    }
    
}