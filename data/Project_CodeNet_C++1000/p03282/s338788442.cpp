#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;
using Graph = vector<vector<pair<int, int>>>;

const ll INF = 1001001001;

int main(){
    string s; cin >> s;
    ll k; cin >> k;
    for(int i = 0; i < min((ll)s.size(), k); i++){
        if(s[i] != '1'){
            cout << s[i] << endl;
            return 0;
        }
    }
    cout << 1 << endl;
}
