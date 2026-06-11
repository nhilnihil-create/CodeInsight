#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    int N;
    cin >> N;
    int buf;
    ll ans = 0;
    for (int i=0; i<N; i++){
        cin >> buf;
        buf--;
        ans += buf;
    }

    cout << ans << endl;
    return 0;
}