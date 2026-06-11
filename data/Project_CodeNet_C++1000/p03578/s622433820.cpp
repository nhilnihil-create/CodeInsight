#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int N, M;
    cin >> N;
    map<int, int> count;
    rep(i, N){
        int d;
        cin >> d;
        count[d]++;
    }
    cin >> M;
    string ans = "YES";
    rep(i, M){
        int t;
        cin >> t;
        if(count[t] <= 0){
            ans = "NO";
            break;
        }
        count[t]--;
    }
    cout << ans << endl;
    return 0;
}
