#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);
int main() {
string s,t;
cin >> s >> t;
sort(s.begin(),s.end());
sort(t.begin(),t.end());
reverse(t.begin(),t.end());

cout << (t>s?"Yes":"No") << endl; 
}