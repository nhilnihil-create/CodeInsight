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

    int n;
    string s;
    cin >> n >> s;

    int r = 0, b = 0;
    rep(i, n){
        if(s[i] == 'R'){
            r++;
        }else{
            b++;
        }
    }

    if(r > b){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}

