#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    string s;
    cin >> s;

    int cnt = 0;
    rep(i, s.size()){
        if(s[i] == 'o') cnt ++;
    }

    if(cnt >= 8 || cnt + 15 - s.size() >= 8){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}

