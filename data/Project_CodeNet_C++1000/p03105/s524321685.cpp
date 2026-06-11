#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int main(void)
{   
    int a, b, c;
    cin >> a >> b >> c;
    int cnt = 0;
    while(b - a >= 0) {
        cnt++;
        if(cnt == c) break;
        b -= a;
    }
    cout << cnt << endl;
    return 0;
}