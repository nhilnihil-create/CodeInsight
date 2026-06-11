#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main(){
    int n, answer = 0;
    cin >> n;
    vector<pair<int, int> > r(n), b(n);
    vector<bool> check(n);
    rep(i, n) cin >> r.at(i).first >> r.at(i).second;
    rep(i, n) cin >> b.at(i).first >> b.at(i).second;
    sort(b.begin(), b.end());
    fill(check.begin(), check.end(), false);
    rep(i, n){
        int y = -1;
        int index = -1;
        rep(j, n) {
            if(r.at(j).first < b.at(i).first && r.at(j).second < b.at(i).second && !check.at(j)){
                if(y < r.at(j).second){
                    y = r.at(j).second;
                    index = j;
                }
            }
        }
        if(y != -1){
            check.at(index) = true;
        }
    }

    rep(i, n) if(check.at(i)) answer++;
    cout << answer << endl;
}