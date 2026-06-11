#include <bits/stdc++.h>
using namespace std;
int main() {
    int N; cin >> N;
    string ans =  "No";
    for (int i=0; i*7<=N; ++i) if ((N-7*i)%4==0) ans = "Yes";
    cout << ans << endl;
    return 0;
}