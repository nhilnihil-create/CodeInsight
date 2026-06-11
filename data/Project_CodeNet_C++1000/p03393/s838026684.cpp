#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,a,b) for (int i = (a); i < (b); i++ )
typedef pair<int,int> P;
typedef long long ll;
const int INF = 100000000;
const double PI=3.14159265358979323846;

int main (){
    string S;
    cin >> S;

    if (S.size()<26) {

        rep(i,0,26) {
            char ans = 'a'+i;
            bool tmp=true;
            rep(j,0,S.size()) {
                if (S[j]==ans) {
                    tmp = false;
                }
            }
            if (tmp){
                cout << S << ans << endl;
                break;
            }
        }
    }
    else if (S == "zyxwvutsrqponmlkjihgfedcba") {
        cout << -1 << endl;
    }

    else {
        string T = S;
        next_permutation(S.begin(),S.end());
        rep(i,0,S.size()) {
            if (T[i]==S[i]){
                continue;
            }
            else {
                rep(j,0,i+1) {
                    cout << S[j];
                }
                cout << endl;
                break;
            }
        }
    }

}

