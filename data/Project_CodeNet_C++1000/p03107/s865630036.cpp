#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    int sum_0, sum_1;
    sum_0 = sum_1 = 0;
    rep(i, 0, s.size()){
        if(s[i] == '0') sum_0++;
        else sum_1++;
    }
    cout << min(sum_0, sum_1)*2 << endl;
    return 0;
}
