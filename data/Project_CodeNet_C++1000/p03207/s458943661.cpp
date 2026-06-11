#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int n;
int p[MAXX];

int main()
{
    _FastIO;
    cin >> n;
    int m = 0;
    int s = 0;
    for(int i = 0; i < n; i++){
        cin >> p[i];
        s += p[i];
        m = max(m , p[i]);
    }
    cout << s - m / 2 << endl;
    return 0;
}
