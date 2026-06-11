#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int m = max({a, b, c});
    if((3*m)%2 == (a+b+c)%2) cout << ((3*m)-(a+b+c))/2 << endl;
    else cout << ((3*(m+1)) - (a+b+c))/2 << endl;

    return 0;
}