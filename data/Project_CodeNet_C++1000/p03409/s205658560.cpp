#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<pair<int, int> > R(N);
    vector<pair<int, int> > B(N);

    vector<bool> C(N);

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        R[i] = make_pair(b, a);
    }

    for(int i = 0; i < N; i++) {
        int c, d;
        cin >> c >> d;
        B[i] = make_pair(c, d);
    }

    sort(R.begin(), R.end(), greater<pair<int, int> >());
    sort(B.begin(), B.end());

    int ans = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(C[j]) continue;
            if(R[j].second < B[i].first && R[j].first < B[i].second) {
                C[j] = true;
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;
}