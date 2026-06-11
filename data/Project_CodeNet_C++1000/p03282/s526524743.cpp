#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;

int main(){
    string s;
    ll k;
    cin >> s >> k;

    int f = 0;
    while(true){
        if(s[f] != '1'){ 
            cout << s[f] << endl;
            return 0;
        }
        else{
            if(f==k-1){
                cout << 1 << endl;
                return 0;
            }
            f++;
        }
        if(f == s.size()) {
            cout << 1 << endl; 
            return 0;
        }
    }
    return 0;
}