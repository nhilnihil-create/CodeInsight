#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(abs(b-a) <= d){
        if(abs(c-b) <= d){
            cout << "Yes" << endl;
            return 0;
        }
    }
    if(abs(a-c) <= d){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}   