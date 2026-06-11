#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);


vector<string> get_str(vector<string> &A, int i, int j, int N) {
    //vector<string> R(N,"");
    vector<string> R;
    rep(h,N) {
        //R[h] = A[(h+i)%N].substr(j,N);
        R.push_back(A[(h+i)%N].substr(j,N));
    }
    return R;
}


int main(){
    int N;
    cin >> N;

    vector<string> A(N,"");
    vector<string> B(N,"");
    rep(h,N) {
        rep(w,N) {
            char a;
            cin >> a;
            A[h].push_back(a);
            B[w].push_back(a);
        }
    }
    rep(i,N) {
        A[i] += A[i];
        B[i] += B[i];
    }
    int ans = 0;
    
    int i = 0;
    rep(j,N) {
        auto R1 = get_str(A,i,j,N);
        auto R2 = get_str(B,j,i,N);
        if (R1==R2) {
            ans += N;
        }
    }

    cout << ans << endl;
}
