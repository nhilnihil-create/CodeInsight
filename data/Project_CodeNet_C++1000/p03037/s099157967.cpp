#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstddef>
#include<queue>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> l(m), r(m);
    for(int i = 0; i < m; ++i){
        cin >> l.at(i) >> r.at(i);
    }
    sort(l.rbegin(), l.rend());
    sort(r.begin(), r.end());
    for(int i = 1; i <= n; ++i){
        if(i >= l.at(0) && i <= r.at(0)) ans++;
    }
    cout << ans << endl;
    return 0;
}