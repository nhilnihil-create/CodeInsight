#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;

void solve() {
    string s, t = "AKIHABARA"; cin >> s; // KIHBR
    if(s.size() > t.size()){
        cout << "NO" << endl;
        return;
    }
    int f = 0;
    rep(i, 0, t.size()){
        if(s[f] != t[i]){
            if(t[i] != 'A'){
                cout << "NO" << endl;
                return;
            }
        }else{
            f++;
        }
    }
    cout << "YES" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
    return 0;
}
 
