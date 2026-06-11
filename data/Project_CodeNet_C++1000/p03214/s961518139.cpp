#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> ii;

const int mod = 1e9 + 7;

int n;

double a[10005], mn = INT_MAX, id;


int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    double sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sum = sum / (double)(n);
    for(int i = 1; i <= n; i++) {
        if(abs(sum - a[i]) < mn) {
            mn = abs(sum - a[i]);
            id = i;
        }
    }
    cout << id - 1 << "\n";
}

