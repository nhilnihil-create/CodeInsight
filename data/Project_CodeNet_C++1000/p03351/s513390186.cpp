#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    int a, b, c, d;
    bool flag = false;
    cin >> a >> b >> c >> d;
    if (abs(a - c) <= d) flag = true;
    else if (abs(a - b) <= d && abs(b - c) <= d) flag = true;
    
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}