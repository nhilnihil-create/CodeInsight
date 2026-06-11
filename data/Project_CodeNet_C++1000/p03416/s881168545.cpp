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


int main(){
    int a, b;
    cin >> a >> b;

    int ans = 0;
    for(int i = a; i <= b; i++){
        string s = to_string(i);
        auto iter0 = s.begin();
        auto iter9 = s.rbegin();
        if(*iter0 == *iter9 && *(iter0 + 1) == *(iter9 + 1)) ans++;
    }
    
    cout << ans << endl;
    return 0;
}
