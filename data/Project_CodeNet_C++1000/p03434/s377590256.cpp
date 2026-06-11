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
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    sort(all(a));
    reverse(all(a));
    int b = 0, al = 0;
    for(int i = 0; i < n; i+= 2) {
        al += a[i];
        b += a[i+1];
    }

    cout << al - b << endl;

    return 0;
}