#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

string s;
int sum;

int main()
{
    _FastIO;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++){
        int k = int(s[i]) - 48;
        if((i % 2) == k)
            sum++;
    }
    int ans = min(sum , (n - sum));
    cout << ans << endl;
    return 0;
}
