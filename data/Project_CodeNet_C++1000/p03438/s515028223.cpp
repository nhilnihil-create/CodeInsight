#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<int>a(N),b(N);
    int suma = 0,sumb = 0;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        suma += a[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> b[i];
        sumb += b[i];
    }
    if(suma > sumb) {
        cout << "No" << endl;
        return 0;
    }
    int res = 0;
    for(int i = 0; i < N; i++) {
        if(a[i] < b[i]) {
            res -= (b[i]-a[i]+1)/2;
            res += (b[i]-a[i])%2;
        }
        else if(a[i] > b[i]) {
            res += a[i]-b[i];
        }
    }
    if(res <= 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
