#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const long long INF = 1LL << 60;
const ll C = 1000000000+7;

int main() {
    int N;
    cin >> N;
    vector<int> odd(100005), even(100005);
    for(int i=1; i<=N; i++) {
        int v;
        cin >> v;
        if(i%2 == 0) {
            odd[v]++;
        }
        else {
            even[v]++;
        }
    }

    vector<int>::iterator iter = max_element(odd.begin(), odd.end());
    int oindex = distance(odd.begin(), iter);
    vector<int>::iterator e_iter = max_element(even.begin(), even.end());
    int eindex = distance(even.begin(), e_iter);

    sort(odd.begin(), odd.end());
    reverse(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    reverse(even.begin(), even.end());

    if(oindex == eindex) {
        if(odd[1] >= even[1]) {
            cout << (N/2) - odd[1] + (N/2) - even[0] << endl;
            return 0;
        }
        else {
            cout << (N/2) - odd[0] + (N/2) - even[1] << endl;
            return 0;
        }
    }
    cout << (N/2) - odd[0] + (N/2) - even[0];
}