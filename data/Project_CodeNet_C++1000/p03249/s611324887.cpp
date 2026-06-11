#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, p[N];
long long a[N], rd[N];


int head[N];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) p[i] = i;
    sort(p + 1, p + n + 1,[](int x,int y){ return a[x] < a[y];});
    fill(head + 1, head + n + 1, 1);

    vector<pair<int, int>> ans;
    for(int i = n; i >= 2; i--) {
        int cur = p[i];
        int L = 1, R = i - 1;
        long long con_weight = a[cur] + 2 * head[cur] - n; 
        while (L <= R){
            int mid = (L + R) / 2;
            if (con_weight > a[p[mid]]) L = mid + 1;
            else R = mid - 1;
        }
        if (L >= i || con_weight != a[p[L]]) {
            cout << "-1" << endl;
            return 0;
        }
        ans.push_back(make_pair(p[L], cur));
        head[p[L]] += head[cur];
        rd[p[L]] += rd[cur] + head[cur];
        //cout << cur << " " << p[L] <<'\n';
        //for(int j = 1; j <= n; j++) cout << head[j] << " \n"[j==n]; 
    }
    if (rd[p[1]] != a[p[1]]) {
        cout << "-1" << endl;
        return 0;
    }
    for(auto i : ans) cout << i.first << " " << i.second << '\n';
}
