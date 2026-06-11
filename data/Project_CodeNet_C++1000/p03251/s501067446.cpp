#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < m; i++)cin >> b[i];
    a.push_back(x), b.push_back(y);

    int nax = *max_element(a.begin(), a.end());
    int niy = *min_element(b.begin(), b.end());

    cout << (niy > nax ? "No War" : "War") << endl;
}