#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    string S;
    cin >> N >> S;

    int count = 0;

    for(int i = 1; i < N; i++) {
        if(S[i] == 'E') count++;
    }

    int ans = count;

    //cerr << ans << endl;

    for(int i = 1; i < N; i++) {
        if(S[i] == 'E') count--;
        if(S[i - 1] == 'W') count++;
        ans = min(ans, count);
        //cerr << count << endl;
    }

    cout << ans << endl;
}