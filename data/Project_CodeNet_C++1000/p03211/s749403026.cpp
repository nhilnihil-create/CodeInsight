#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int main()
{
    _FastIO;
    string s;
    cin >> s;
    int n = s.size();
    int x = 0;
    int ans = 753;
    for(int i = 0; i < 3; i++){
        int k = int(s[i]) - 48;
        x = x * 10 + k;
    }
    ans = min(ans , abs(753 - x));
    int i = 3;
    while(i < n){
        x %= 100;
        int k = int(s[i]) - 48;
        x = x * 10 + k;
        ans = min(ans , abs(753 - x));
        i++;
    }
    cout << ans << endl;
    return 0;
}
