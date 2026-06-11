#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {
    int N; cin >> N;
    vector<P> a(N);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        a[i].first = x;
        a[i].second = i;
    }

    sort(a.begin(), a.end());
    int mi = a[0].first;
    int imi = a[0].second;
    
    sort(a.begin(), a.end(), greater<P>());
    int ma = a[0].first;
    int ima = a[0].second;
    
    vector<P> vec;
    
    if (abs(ma) > abs(mi)) {
        for (int i = 0; i < N; i++) {
            if (i == ima) continue;
            a[i].first += ma;
            vec.push_back(P(ima, i));
        }
        for (int i = 1; i < N; i++) {
            a[i].first += a[i-1].first;
            vec.push_back(P(i-1, i));
        }
    }
    else {
        for (int i = 0; i < N; i++) {
            if (i == imi) continue;
            a[i].first += mi;
            vec.push_back(P(imi, i));
        }
        for (int i = N-1; i > 0; i--) {
            a[i-1].first += a[i].first;
            vec.push_back(P(i, i-1));
        }
    }
    
    cout << vec.size() << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i].first+1 << " " << vec[i].second+1 << endl;
    }
    return 0;
}