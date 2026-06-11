#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    int ans = 0;
    
    rep(i, 1, N-1){
        vector<char>x;
        vector<char>y;
        rep(j, 0, i) x.push_back(S[j]);
        rep(j, i, N) y.push_back(S[j]);
        vector<bool>xb(x.size(), true);
        vector<bool>yb(y.size(), true);

        set<char> count;

        rep(j, 0, x.size()){
            rep(k, 0, y.size()){
                if(x[j] == y[k] && xb[j] == true && yb[k] == true){
                    xb[j] = false;
                    yb[k] = false;
                    count.insert(x[j]);
                }
            }
        }
        int tempans = count.size();
        ans = max(ans, tempans);
    }
    cout << ans << endl;
}

