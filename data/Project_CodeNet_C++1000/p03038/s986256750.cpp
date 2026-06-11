#include <bits/stdc++.h>

typedef long long ll;
#define IO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define endl '\n'
const int N = 1e5 + 10;
const int OO = 1e9;
using namespace std;

int main() {
    IO;
    priority_queue<int, vector<int>, greater<>> q;
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        q.push(x);
    }
    vector<pair<int, int>> v;
    while (t--) {
        int kam, value;
        cin >> kam >> value;
        v.push_back({value, kam});
    }
    sort(v.rbegin(), v.rend());
    for (auto &i:v) {
        while (q.top() < i.first && i.second--) {
            q.pop();
            q.push(i.first);
        }
    }
    ll sum=0;
    while(!q.empty()){
        sum+=ll(q.top());
        q.pop();
    }
    cout<<sum;


}
