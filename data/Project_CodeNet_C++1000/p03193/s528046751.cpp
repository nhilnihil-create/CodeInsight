#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N,H,W;
    cin >> N >> H >> W;
    int ans = 0;
    rep(i,N){
        int A,B;
        cin >> A >> B;
        if (H <= A && W <= B) ans++;
    }
    cout << ans << endl;
}
