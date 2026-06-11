#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1LL << 60;

int main() {
    

    ll N;
    cin >> N ;
    ll count_n = 0;

    rep(i,N){
        ll count = 1;
        if(((i+1)%2) == 1){
            //cout << i+1 << endl;
            rep(j,i){
                if(((i+1)%(j+1)) == 0){
                    count += 1;
                }
            }
            //cout << i+1 << " " << count << endl;
            if(count == 8){
                count_n += 1;
            }
        }
    }

    cout << count_n << endl;

}