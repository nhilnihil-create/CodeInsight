#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int M,K;
    cin >> M >> K;
    if (M == 0){
        if (K == 0){
            cout << "0 0" << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    else if (M == 1){
        if (K == 0){
            cout << "0 0 1 1" << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    else{
        int m = 1;
        rep(i,M){
            m *= 2;
        }
        if (K >= m){
            cout << -1 << endl;
        }
        else{
            vector<int> ans(0);
            rep(i,m){
                if (i != K) ans.push_back(i);
            }
            ans.push_back(K);
            for (int i = m - 1; i >= 0; i--){
                if (i != K) ans.push_back(i);
            }
            ans.push_back(K);
            rep(i,2 * m){
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
}
