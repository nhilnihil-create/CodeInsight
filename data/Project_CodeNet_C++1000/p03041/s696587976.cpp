#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i < (n); i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    if (s[k-1] == 'A') s[k-1] = 'a';
    else if(s[k-1] == 'B')s[k-1] = 'b';
    else s[k-1] = 'c';
    cout << s << endl;
    
}