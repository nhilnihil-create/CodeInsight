#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
using namespace std;
using ll = long long;
using P  = pair<int, int>;
int main()
{
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<char>());
    // cout << s << endl;
    // cout << t << endl;
    if(s < t) cout << "Yes" << endl;
    else      cout << "No"  << endl;
}
