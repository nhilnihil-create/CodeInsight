#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, b) for (int i = 0; i < (b); i++ )

typedef pair<int,int> P;
typedef long long ll;

const int INF = 100000000;
const double PI=acos(-1);

int main () {
    int N;
    cin >> N ;
    int C[N],S[N],F[N];

    rep(i,N-1) {
        cin >>C[i] >> S[i] >> F[i];
    }
    
    vector<int> a(N,0);

    rep(j,N-1) {
        for (int i = 0; i<=j; i++){
            if (max(a[i],S[j])%F[j]==0) {
                a[i] = max(a[i],S[j])+C[j];

            }
            else {
                int tmp = (max(a[i],S[j])+F[j])/F[j];
                a[i] = tmp*F[j]+C[j];
            }
        }
    }
    rep(i,N) {
        cout << a[i] << endl;
    }
}