#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
#define llINF 1000000000000000007
#define v(i) vector<i>
#define vv(i) vector<vector<i>>
// cin.eof() 入力個数の問題
// int num = atoi(string.c_str()); 文字列の整数変換

int main() {
    int n;
    cin >> n;
    ll d[n];
    map<ll, int> md, mt;
    rep(i, n) {
        cin >> d[i];
        md[d[i]]++;
    }
    int m;
    cin >> m;
    ll t[m];
    rep(i, m) { 
        cin >> t[i];
        mt[t[i]]++;
         }
    
    
    if (n < m) {
        cout << "NO" << endl;
        return 0;
    }
    for(auto i : mt){
        if(md[i.first]<i.second){
            cout<<"NO"<<endl;
            return 0;
        }
    }


    cout << "YES" << endl;

    return 0;
}
