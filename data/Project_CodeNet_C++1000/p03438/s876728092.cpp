#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> ii;

const int N = 1e4 + 5;

int n;

int a[N], b[N];
long long cons = 0;

long long sumA, sumB;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sumA += a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        sumB += b[i];
    }
    if(sumA > sumB) {cout << "No\n"; return 0;}
    for(int i = 1; i <= n; i++){
        if(a[i] < b[i])
            cons -= (b[i] - a[i]) / 2;
        else
            cons += a[i] - b[i];
    }
    if(cons > 0)
        cout << "No\n";
    else
        cout << "Yes\n";
}
