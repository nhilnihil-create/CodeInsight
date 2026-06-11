#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N,C;
    cin >> N >> C;
    vector<vector<int>> A(N,vector<int> (3));
    rep(i,N) {
        int s,t,c;
        cin >> s >> t >> c;
        A[i][0] = s;
        A[i][1] = t;
        A[i][2] = c;  
    }
    sort(A.begin(),A.end());
    vector<pair<int,int>> B;

    int now = 0;

    rep(i,N) {
        int s,t,c;
        s = A[i][0];
        t = A[i][1];
        c = A[i][2];

        now = s;
        bool tu = true;
        rep(i,B.size()) {
            if (c==B[i].second) {
                if (now>=B[i].first) {
                    B[i].first = t;
                    tu = false;
                }
            }
            else {
                if (now>B[i].first) {
                    B[i].first = t;
                    B[i].second = c;
                    tu = false;
                }
            }

            if (!tu) break;
        }
        if (tu) {
            B.push_back(make_pair(t,c));
        }
    }

    cout << B.size() << endl;

}
