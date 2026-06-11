#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<int> a(N), b(N);
    rep(i, N){
        cin >> a[i];
    }
    rep(i, N){
        cin >> b[i];
    }

    ll pool = 0;
    rep(i, N){
        if(a[i] > b[i]){
            pool += (a[i] - b[i])*2;
        }
    }

    rep(i, N){
        if(a[i] < b[i]){
            int x = b[i] - a[i];
            if(x%2 == 1)x--;
            pool -= x;
        }
    }

    if(pool <= 0){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}