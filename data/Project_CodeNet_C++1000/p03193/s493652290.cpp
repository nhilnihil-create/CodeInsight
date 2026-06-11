#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,H,W; cin >> N >> H >> W;
    int ans=0;
    for (;N--;){
        int A,B; cin >> A >> B;
        ans+=(H<=A&&W<=B);
    }
    cout << ans << '\n';
}