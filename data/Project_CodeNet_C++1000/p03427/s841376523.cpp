#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
//const int N = 1000000;
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
    ll n; cin >> n;
    string s = to_string(n);
    int m = s.length();
    int j = 0;
    int count = 0;
    while(j < m && m > 1){
        if(s[j] != '9' && j != m - 1){
            s[j]--;
            _rep(i, j + 1, m){
                if(s[i] != '9'){
                    s[i] = '9';
                    count++;
                }
            }
            if(count == 0)s[j]++;
            break;
        }else if(s[j] != '9'){
            s[j - 1]--;
            s[j] = '9';
            break;
        }
        j++;
    }
    int ans = 0;
    rep(i, m){
        ans += s[i] - '0';
    }
    //cout << s << endl;
    cout << ans << endl;
}
