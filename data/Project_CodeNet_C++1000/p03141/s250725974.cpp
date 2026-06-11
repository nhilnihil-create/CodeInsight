#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define endl '\n'
#define all(v) (v).begin(),(v).end()
#define int long long
#define P pair<int,int>

signed main() {
    int n;
    cin >> n;

    int X = 0;
    vector<tuple<int,int,int>> v;
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;

        X -= b;
        int c = a + b;
        v.emplace_back(c,a,b);
    }
    sort(all(v));
    reverse(all(v));

    for(int i = 0; i < n; i+=2){
        X += get<0>(v[i]);
    }
    cout << X << endl;
}