#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> d(N);
    for(int i=0; i<N; i++) cin >> d.at(i);
    sort(d.begin(), d.end());
    reverse(d.begin(), d.end());
    int ans = 1;
    int m = d.at(0);
    for(int i=1; i<N; i++){
        if( m > d.at(i) ) {
            ans++;
            m = d.at(i);
        }
    }

    cout << ans << endl;
}