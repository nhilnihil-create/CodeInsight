#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int ,int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005


int main()
{
    _FastIO;
    int n;
    cin >> n;
    vector<int> a(n + 5 , 0);
    int s = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
    }
    cout << s - n << endl;
    return 0;
}
