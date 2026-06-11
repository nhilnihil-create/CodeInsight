#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    string s, t, d;

    cin >> n >> q >> s;
    t = string(q, 'A');
    d = string(q, 'R');
    for(int i=0;i<q;i++) cin >> t[i] >> d[i];

    int lft = 0, rit = n-1;
    for(int i=q-1;i>=0;i--){
        if(lft >= 0 && lft < n && t[i] == s[lft] && d[i] == 'L') lft++;
        if(lft-1 >= 0 && lft-1 < n && t[i] == s[lft-1] && d[i] == 'R') lft--;
        if(rit >= 0 && rit < n && t[i] == s[rit] && d[i] == 'R') rit--;
        if(rit+1 >= 0 && rit+1 < n && t[i] == s[rit+1] && d[i] == 'L') rit++;
    }

    cout << rit - lft + 1 << endl;
	return 0;
}
