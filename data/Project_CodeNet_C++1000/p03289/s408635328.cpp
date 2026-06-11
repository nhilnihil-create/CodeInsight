#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int N = 1000000;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}

/*------------------------------------------------------------------*/


int main(){
    string s; cin >> s;
    bool flag = true;
    if(s[0] != 'A') flag = false;
    int count = 0;
    _rep(i, 2, s.size() - 1){
        if(s[i] == 'C') count++;
    }
    if(count != 1) flag = false;
    int cou = 0;
    rep(i, s.size()){
        if(isupper(s[i])) cou++;
    }
    if(cou != 2) flag = false;
    if(flag) cout << "AC" << endl;
    else cout << "WA" << endl;
}