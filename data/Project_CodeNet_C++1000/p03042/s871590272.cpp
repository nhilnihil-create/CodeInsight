#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int a = stoi(s.substr(0, 2));
    int b = stoi(s.substr(2, 2));
    
    bool oka = (a >= 1 && a <= 12);
    bool okb = (b >= 1 && b <= 12);
    if (oka && okb) cout << "AMBIGUOUS\n";
    else if (oka) cout << "MMYY\n";
    else if (okb) cout << "YYMM\n";
    else cout << "NA\n";
}
