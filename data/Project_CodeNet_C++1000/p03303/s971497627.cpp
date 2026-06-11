#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;

int main(){
    string S;
    int w;
    cin >> S >> w;
    rep(i, S.size()){
        if(i % w == 0){
            cout << S[i];
        }
    }
    cout << endl;
    return 0;
}
