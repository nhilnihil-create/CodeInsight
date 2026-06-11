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
    long long n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long> > a(n + 1);
    long long l, r;
    for(int i = 0; i < m; ++i){
        cin >> l >> r;
        a[l].push_back(r);
    }
    for(int i = 1; i <= n; ++i) sort(a[i].begin(), a[i].end());

    
    for(int i = 0; i < q; ++i){
        long long ans = 0;
        cin >> l >> r;
        for(int j = l; j <= r; ++j){
            ans += upper_bound(a[j].begin(), a[j].end(), r) - a[j].begin();
        }
        cout << ans << endl;
    }

}