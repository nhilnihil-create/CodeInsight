#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n; cin >> n;vector<int> a(n); 
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= (i + 1);
    }
    sort(a.begin(), a.end());
    ll med = a[n / 2];
    ll sum = 0;

    for(int i = 0; i < n; i++) {
        sum += abs(a[i] - med);
    }
    cout << sum << endl;
}