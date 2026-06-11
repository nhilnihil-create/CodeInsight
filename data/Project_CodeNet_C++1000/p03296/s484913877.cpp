#include <bits/stdc++.h>
#define rep(i,n) for(long long int i = 0; i < n; i++)
#define print(n) std::cout << n << std::endl
#define _print(n) std::cout << n
using namespace std;
typedef long long ll;
const int N = 1000000;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int count = 0;
    for (int i = 0; i < n - 2; ++i) {
        if(a[i] == a[i + 1] && a[i + 1] == a[i + 2]){
            count++;
            a[i + 1] = 0;
        }else if(a[i] == a[i + 1] && a[i] != a[i + 2]){
            count++;
            a[i + 1] = 0;
        }
    }
    if(a[n - 2] == a[n - 1])count++;
    print(count);
}

