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
    int sz[MAXN], p[MAXN];
    
    void MakeSet(int x){
        p[x] = x;
        sz[x] = 1;
    }

    int Find(int x){
        if(p[x] != x) p[x] = Find(p[x]);
        return p[x];
    }

    void Union(int x, int y){
        x = Find(x), y = Find(y);
        if(sz[x] > sz[y]) swap(x, y);
        if(p[x] == y || p[y] == x) return;
        p[x] = y;
        sz[y] += sz[x];
    }
};

int main(){
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        a[i]--;
    }
    FndUn f;
    for(int i = 0; i < n; ++i) f.MakeSet(i);
    long long m1, m2;
    for(int i = 0; i < m; ++i){
        cin >> m1 >> m2;
        m1--, m2--;
        f.Union(m1, m2);
    }
    long long ans = 0;
    for(int i = 0; i < n; ++i){
        if(f.Find(a[i]) == f.Find(i)) ans++;
    }
    cout << ans;
}