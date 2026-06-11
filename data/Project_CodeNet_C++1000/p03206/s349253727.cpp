#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int d;

int main()
{
    _FastIO;
    cin >> d;
    string ans = "Christmas";
    int k = 25 - d;
    for(int i = 0; i < k; i++){
        ans += " Eve";
    }
    cout << ans << endl;
    return 0;
}
