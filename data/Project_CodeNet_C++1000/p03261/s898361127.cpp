#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
using namespace std;
#define INF 1e18LL

const ll MAX = 1000000000000000000; //1e18

int main(){
    int n; cin >> n;
    vector<string> w(n);
    bool exist = false;
    rep(i, n){
        cin >> w[i];
        rep(j, i){
            if(w[i] == w[j]){
                exist = true;
            }
        }
    }
    if(exist){
        cout << "No" << endl;
        return 0;
    }
    for(int i = 1; i < n; i++){
        string s1 = w[i-1];
        char c1 = s1[s1.size()-1];
        string s2 = w[i];
        char c2 = s2[0];
        if(c1 != c2){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;

}

