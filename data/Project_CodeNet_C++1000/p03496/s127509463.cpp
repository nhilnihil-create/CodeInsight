#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;
const int MOD = 1000000007;


int main(){

    int N; cin >> N;
    vector<int> a(N);
    int max_abs = -1;
    int max_abs_index = -1;
    bool isMinus = false;
    rep(i,N) {
        cin >> a[i];
        if (max_abs < abs(a[i])){
            max_abs = abs(a[i]);
            max_abs_index = i;
            if (a[i] < 0) {
                isMinus = true;
            }
            else{
                isMinus = false;
            }
        }
    }
    

    cout << (N-1)*2 << endl;

    rep(i,N){
        if (i == max_abs_index) continue;
        cout << max_abs_index+1 << " " << i+1 << endl; 
    }

    if (!isMinus){
        for(int i = 0; i < N-1; i++){
            cout << i+1 << " " << i+2 << endl;
        }
    }
    else{
        for(int i = N-1; i > 0; i--){
            cout << i+1 << " " << i << endl;
        }
    }



}