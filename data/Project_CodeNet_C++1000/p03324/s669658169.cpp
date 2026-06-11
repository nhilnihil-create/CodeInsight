#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0);
    int d, n; cin >> d >> n;


    if (d==0) {
        cout << n+(n==100) << endl;
    } else if (d==1) {
        cout << 100*(n+(n==100)) << endl;
    } else {
        cout << 10000*(n+(n==100)) << endl;
    }
}
