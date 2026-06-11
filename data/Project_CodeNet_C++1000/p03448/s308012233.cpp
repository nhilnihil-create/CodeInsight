#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
typedef vector<int> vi;

int main(){
    int A, B, C, X;
    cin >> A >> B >> C >> X;

    int ans = 0;
    rep(i, A+1){
        rep(j, B+1){
            rep(k, C+1){
                if(500*i + 100*j + 50*k == X) ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}