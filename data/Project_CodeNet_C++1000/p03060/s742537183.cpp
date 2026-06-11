#include<bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;

using ll = long long;
const int N = 1e5+5;

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] - b[i] > 0) {
            sum += (a[i]-b[i]);
        }
    }
    cout << sum;
    return 0;
}
