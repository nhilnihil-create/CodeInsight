#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define per(i,n) for (int i=n-1; i>=0; --i)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;
using ll = long long;
using P  = pair<int,int>;
using vi = vector<int>;
using vv = vector<vi>;
const int mod = 1000000007;
//const int mod = 998244353;

int main(){
    int n, k;
    cin >> n >> k;
    printf("%c\n", (n%k)?'1':'0');
    return 0;
}