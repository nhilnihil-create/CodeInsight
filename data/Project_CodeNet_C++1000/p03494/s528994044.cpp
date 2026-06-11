#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    vector<int> A(N,0);
    int now = 1000000000;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
        ans = 0;
        while(!(A.at(i)%2)) {
            ans++;
            //cout << ans << endl;
            //cout << "###" << endl;
            A.at(i) /= 2;
        }
        //cout << ans << endl;
        now = min(ans,now);
    }
    cout << now << endl;



    return 0;
}