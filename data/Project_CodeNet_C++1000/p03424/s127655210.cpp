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
    int n;
    cin >> n;
    vector<int> l(4);
    rep(i, n) {
        char a;
        cin >> a;
        if(a == 'P') l[0]++;
        else if(a == 'W') l[1]++;
        else if(a == 'G') l[2]++;
        else l[3]++;
    }

    int ans = 0;
    rep(i, 4) {
        if(l[i] > 0) ans++;
    }
    if(ans == 3) cout << "Three" << endl;
    else cout << "Four" << endl;

    return 0;
}