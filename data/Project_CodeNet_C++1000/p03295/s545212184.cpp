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

bool cmp(const pair<long long, long long> &a, const pair<long long, long long> &b){
    return a.second < b.second;
}

int main(){
    long long n, m;
    cin >> n >> m;
    vector<pair<long long, long long> > a(m);
    for(int i = 0; i < m; ++i) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end(), cmp);
    set<long long> ans;
    for(int i = 0; i < m; ++i){
        auto k = ans.lower_bound(a[i].first);
        if(k == ans.end() || *k >= a[i].second){
            ans.insert(a[i].second - 1);
        }
    }
    cout << ans.size();
}
