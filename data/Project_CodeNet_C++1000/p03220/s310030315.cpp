#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 100005

int n , t , x;
int a[MAXX];

int main()
{
    _FastIO;

    cin >> n;
    cin >> t >> x;
    vector<pair<double , int> > v;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        v.push_back({(double(abs((x * 1.0) - (t - a[i] * 6 * 1.0 / 1000)))) , (i)});
    }
    sort(v.begin() , v.end());
    cout << v[0].second << endl;
    return 0;
}
