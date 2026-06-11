#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const int INF = 1001001001;

int main(){
    int n; cin >> n;
    int xa = 0, bx = 0, bxa = 0;
    vector<string> s(n);
    int cnt = 0;
    rep(i,n) cin >> s.at(i);
    rep(i,n){
        if(s.at(i).at(0) == 'B' && s.at(i).at((int)(s.at(i).size() - 1)) == 'A'){
            bxa++;
        }else if(s.at(i).at(0) == 'B') bx++;
        else if(s.at(i).at((int)(s.at(i).size() - 1)) == 'A') xa++;
        for(int j=1;j<(int)(s.at(i).size());j++){
            if(s.at(i).at(j) == 'B' && s.at(i).at(j-1) == 'A') cnt++;
        }
    }
    cout << cnt + min(xa,bx) + bxa - (xa == 0 && bx == 0) + (xa == 0 && bx == 0 && bxa ==0) << endl;
}