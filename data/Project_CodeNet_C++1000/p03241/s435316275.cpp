#include<bits/stdc++.h>
using namespace std;
int main(){
    long long N,M;
    cin >> N >> M;
    int ans;
    for (int i = M / N; i >= 1; i--) {
        if (M % i == 0) {
          ans = i;
          break;
        }
    }
    cout << ans << endl;
}