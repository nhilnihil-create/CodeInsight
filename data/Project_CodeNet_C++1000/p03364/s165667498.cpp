#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);


int main(){
    int N;
    cin >> N;

    vector<string> A(N,"");
    rep(h,N) {
        rep(w,N) {
            char a;
            cin >> a;
            A[h].push_back(a);
        }
    }

    int ans = 0;    
    rep(i,N) {
        bool t = true;
        vector<string> B(N,"");
        rep(h,N) {
            rep(w,N) {
                B[h] += A[h][(w+i)%N];
            }
        }



        rep(h,N) {
            rep(w,N) {
                if (B[h][(w+i)%N]!=B[(w+i)%N][h]) {
                    t = false;
                }
            }
        }

        if (t) {
            ans += N;
        }
    }

    cout << ans << endl;
}
