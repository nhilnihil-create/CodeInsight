#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int s , n , k;

int main()
{
    _FastIO;

    cin >> n >> k;
    int x , y;
    for(int i = 1; i <= n; i++){
        cin >> x;
    }
    n -= k;
    cout << (n + k - 2) / (k - 1) + 1 << endl;
    return 0;
}
