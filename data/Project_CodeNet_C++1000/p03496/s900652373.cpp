#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<ll> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    ll d = *max_element(a.begin(), a.end());
    ll s = *min_element(a.begin(), a.end());

    int count = 0;
    vector<pair<int, int> > ans;

    if(abs(d) >= abs(s)) {
        for(int i = 1; i < N; i++) {
            while(a[i] < a[i - 1]) {
                int p = max_element(a.begin(), a.end()) - a.begin();
                ll x = a[p];
                for(int j = 0; j < N; j++) {
                    if(a[j] >= a[i - 1] - a[i]) {
                        if(a[j] < x) {
                            p = j;
                            x = a[j];
                        }
                    }
                }
                count++;
                ans.push_back(make_pair(p + 1, i + 1));
                a[i] += x;
            }
        }
    } else {
        for(int i = N - 2; i >= 0; i--) {
            while(a[i] > a[i + 1]) {
                int p = min_element(a.begin(), a.end()) - a.begin();
                ll x = a[p];
                for(int j = 0; j < N; j++) {
                    if(a[j] <= a[i + 1] - a[i]) {
                        if(a[j] > x) {
                            p = j;
                            x = a[j];
                        }
                    }
                }
                count++;
                ans.push_back(make_pair(p + 1, i + 1));
                a[i] += x;
            }
        }
    }

    cout << count << endl;

    for(int i = 0; i < count; i++) cout << ans[i].first << " " << ans[i].second << endl;
}