#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int n , k;

int main()
{
    _FastIO;
    cin >> n >> k;
    cout << min(1 , n % k) << endl;
    return 0;
}
