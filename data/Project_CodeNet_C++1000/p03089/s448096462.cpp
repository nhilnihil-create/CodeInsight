#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n-1); i >= 0; i--)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;


int main(){
    int N; cin >> N;
    vector<int> b(N);
    b.assign(N,0);
    rep(i,N){
        cin >> b[i];
        b[i]--;
    } 

    vector<int> a;

    rep(i,N){
        int index = -1;
        rrep(j,b.size()){
            if (b[j] == j){
                index = j;
                break;
            }
        }

        if (index == -1){
            cout << -1 << endl;
            return 0;
        }

        a.push_back(index+1);
        b.erase(b.begin() + index);
    }

    reverse(a.begin(), a.end());
    rep(i,a.size())
    {
        cout << a[i] << endl;
    }


}

    