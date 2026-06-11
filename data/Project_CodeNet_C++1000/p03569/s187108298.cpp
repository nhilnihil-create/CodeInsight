#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;
typedef pair<int,int> pr;
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main(){
    string s; cin >> s;
    ll ans = 0;
    ll left = 0, right = s.length()-1;

    while(left < right){
        if(s[left] != 'x' && s[right] != 'x' && s[left] != s[right]){
            cout << -1;
            return 0;
        }else if(s[left] == s[right]){
            left ++;
            right --;
        }else if(s[left] == 'x'){
            left ++;
            ans ++;
        }else if(s[right] == 'x'){
            right --;
            ans ++;
        }
    }
    cout << ans;

}