#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<int> to[200005];

int main()
{
    int n;
    cin >> n;
    vector<string> w(n);
    rep(i, 0, n) cin >> w[i];
    map<string, int> mp;
    rep(i, 0, n){
        if(mp[w[i]]){
            cout << "No" << endl;
            return 0;
        }
        if(i > 0){
            if(w[i-1][w[i-1].size()-1] != w[i][0]){
                cout << "No" << endl;
                return 0;
            }
        }
        mp[w[i]]++;
    }
    cout << "Yes" << endl;
    return 0;
}
