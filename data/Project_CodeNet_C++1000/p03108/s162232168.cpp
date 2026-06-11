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

const int MAXN = 1e5;
    
struct FndUn{
    int p[MAXN], sz[MAXN];

    void MakeSet(int x){
        p[x] = x;
        sz[x] = 1;
    }

    int Find(int x){
        if(p[x] != x) p[x] = Find(p[x]);
        return p[x];
    }

    pair<int, int> Union(int x, int y){
        x = Find(x), y = Find(y);
        if(sz[x] > sz[y]) swap(x, y);
        if(p[x] == y || p[y] == x) return make_pair(0, 0);
        p[x] = y;
        int pr1 = sz[x], pr2 = sz[y];
        sz[y] += sz[x];
        return make_pair(pr1, pr2);
    }

    int Size(int x){
        return sz[Find(x)];
    }
};

int main(){
    long long n, m;
    cin >> n >> m;
    vector<pair<long long, long long> > a(m);
    for(int i = 0; i < m; ++i){
        cin >> a[i].first >> a[i].second;
        a[i].first--, a[i].second--;
    }
    FndUn f;
    for(int i = 0; i < n; ++i){
        f.MakeSet(i);
    }
    vector<long long> ans(m);
    ans[m - 1] = n * (n - 1) / 2;
    for(int i = m - 2; i >= 0; --i){
        auto mns = f.Union(a[i + 1].first, a[i + 1].second);
        long long m1 = mns.first, m2 = mns.second;
        ans[i] = ans[i + 1] - (m1 + m2) * (m1 + m2 - 1) / 2;
        ans[i] += m1 * (m1 - 1) / 2;
        ans[i] += m2 * (m2 - 1) / 2;
    }
    for(int i = 0; i < m; ++i) cout << ans[i] << endl;
}
