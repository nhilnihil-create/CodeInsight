#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi   = vector<int>;
using vll  = vector<ll>;
using vc   = vector<char>;
using vvll  = vector<vll>;
using vvi  = vector<vi>;
using vvc  = vector<vc>;
using vb   = vector<bool>;
using vvb  = vector<vb>;
using pii  = pair<int,int>;
using vpii = vector<pii>;
using posteriority_queue = priority_queue<int, vi, greater<int>>;
 
//DP template
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;} 
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
const ll INF = 1LL << 60;
vll dp(1000000, INF);

//mod template
const ll MOD = 1000000007;

//input var
int N;

int main() {
    //input
    cin >> N;
    // for (int i = 0; i < N; i++) cin >> a.at(i);
     
    //IC
    dp.at(0) = 0;


    //loop
    for (int i = 0; i <= N; i++) {
        int tmp;
        // case 1
        chmin(dp.at(i+1), dp.at(i)+1);
        
        // case 6
        tmp = 6;
        while(i+tmp <= N){
            chmin(dp.at(i+tmp), dp.at(i)+1);
            tmp*=6;
        }

        // case 9
        tmp = 9;
        while(i+tmp <= N){
            chmin(dp.at(i+tmp), dp.at(i)+1);
            tmp*=9;
        }
    }

    //output
    cout << dp.at(N) << endl;

}