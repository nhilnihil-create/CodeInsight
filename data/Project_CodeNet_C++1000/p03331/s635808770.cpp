#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define vv(T) vector<vector<T>>
#define coa cout << ans << endl
using namespace std;
using ll = long long;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using vbool = vector<bool>;
using vvbool = vector<vector<bool>>;
using qint = queue<int>;
using sint = stack<int>;
using pii = pair<int, int>;

int sumOfDigits(int x){
    int ret = 0;
    while(x){
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

int main(){
    int n;
    cin >> n;

    int ans = INT32_MAX;
    for(int a = 1; a < n; a++){
        int b = n - a;
        ans = min(ans, sumOfDigits(a) + sumOfDigits(b));
    }

    cout << ans << endl;
    return 0;
}
