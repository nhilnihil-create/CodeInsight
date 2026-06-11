#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int N = 1000000;
const ll mod = 1000000007;
using Graph = vector<vector<int>>;
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
    string s, t; cin >> s >> t;

    vector<int> ss(26, 0), tt(26, 0);


    rep(i, s.size()){
        int j = 0;
        for(char c = 'a'; c <= 'z'; c++){
            if(s[i] == c) ss[j]++;
            if(t[i] == c) tt[j]++;
            j++;
        }
    }
    sort(ss.begin(), ss.end());
    sort(tt.begin(), tt.end());
    bool flag = true;
    rep(i, 26){
        if(ss[i] != tt[i]) flag = false;
    }
    cout << (flag ? "Yes" : "No") << endl;
}

