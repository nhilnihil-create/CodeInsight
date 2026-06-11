#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    string ans = s.substr(0, n - 8);
    cout << ans << endl;
}