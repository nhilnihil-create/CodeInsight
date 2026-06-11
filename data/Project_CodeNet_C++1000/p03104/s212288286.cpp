// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;


int main(){
    ll A, B;
    cin >> A >> B;
    if(A % 2 == 0 && B % 2 == 1){
        ll gap = B - A + 1;
        if(gap % 4 == 0) cout << 0 << endl;
        else cout << 1 << endl;
    } else if(A % 2 == 1 && B % 2 == 1){
        ll gap = B - (A + 1) + 1;
        ll C;
        if(gap % 4 == 0) C = 0;
        else C = 1;
        cout << (A ^ C) << endl;
    } else if(A % 2 == 0 && B % 2 == 0){
        ll gap = (B - 1) - A + 1;
        ll C;
        if(gap % 4 == 0) C = 0;
        else C = 1;
        cout << (B ^ C) << endl;
    } else {
        ll gap = (B - 1) - (A + 1) + 1;
        ll C;
        if(gap % 4 == 0) C = 0;
        else C = 1;
        cout << (A ^ B ^ C) << endl;
    }

    
}