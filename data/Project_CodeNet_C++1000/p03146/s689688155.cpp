#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 100005

int s , t;
bool used[MAXX];

int main()
{
    _FastIO;
    cin >> s;
    int ans = 0;
    used[s] = true;
    t = 1;
    while(true){
            t++;
        if(s % 2 == 0)
            s /= 2;
        else
            s = s * 3 + 1;
        if(used[s]){
            ans = t;
            break;
        }
        used[s] = true;
    }
    cout << ans << endl;
    return 0;
}
