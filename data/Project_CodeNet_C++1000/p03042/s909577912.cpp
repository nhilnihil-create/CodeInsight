#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define ft first
#define sd second
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<char,char> pcc;
typedef pair<long long,long long> pll;

int main() {
    fastIO;
    string s;
    bool y = false, m = false;
    cin >> s;
    if((s[0] < '1' || s[1] < '3') && (s[0] != '0' || s[1] != '0')) m = true;
    if((s[2] < '1' || s[3] < '3') && (s[2] != '0' || s[3] != '0')) y = true;

    if(m && y) cout << "AMBIGUOUS" << endl;
    else if(m) cout << "MMYY" << endl;
    else if(y) cout << "YYMM" << endl;
    else cout << "NA" << endl;
    return 0;
}

