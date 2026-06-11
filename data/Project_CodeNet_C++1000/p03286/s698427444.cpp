#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    string ans = "";

    int re = -1;

    if(N == 0) {
        cout << 0 << endl;
        return 0;
    }

    while(N != 0) {
        if(N % 2) {
            N += re;
            ans += "1";
        } else {
            ans += "0";
        }

        //cerr << N << endl;
        if(abs(N) != 1) N /= 2;
        re = -re;
    }

    reverse(ans.begin(), ans.end());

    cout << ans << endl;
}