#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(100001), b(100001);
    for (int i = 0; i < 100001; i++)
    {
        a[i] = make_pair(0, i + 1);
        b[i] = make_pair(0, i + 1);
    }
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        if (i % 2 == 0)
            a[v].first++;
        else
        {
            b[v].first++;
        }
    }
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    ll mxa = a[0].first,mxb = b[0].first;
    if(a[0].second == b[0].second){
        if(a[1].first > b[1].first)
        mxa = a[1].first;
        else if(a[1].first < b[1].first)
        mxb = b[1].first;
        else if(a[1].first == 0 && b[1].first == 0){
            cout << n / 2 << endl;
            return 0;
        }
    }
    cout << n - mxa - mxb << endl;
}
