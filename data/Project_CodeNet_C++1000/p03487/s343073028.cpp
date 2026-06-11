#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, b) for (int i = 0; i < (b); i++ )

typedef pair<int,int> P;
typedef long long ll;

const int INF = 100000000;
const double PI=acos(-1);

bool comp(P p1, P p2){
    if (p1.first != p2.first) {
        return p1.first < p2.first;
    }
    else if (p1.second != p2.second) {
        return p1.second > p2.second;
    }
    else {
        return true;
    }
}


int main () {
    int N;
    cin >> N;

    int a[N];
    map<int,int> m;

    rep(i,N) {
        cin >> a[i];
        if (!m.count(a[i])) {
            m[a[i]] = 1;
        }
        else {
            m[a[i]]++;
        }
    }

    int ans = 0;
    int value,n;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        n = iter->first;
        value = iter->second;
        if (n==value) {
            continue;
        }
        else if (n<value) {
            ans += value-n;
        }
        else {
            ans += value;
        }
    }
 

    cout << ans << endl;

}
