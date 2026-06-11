#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const int INF = 1e9 + 6;
const int MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()

bool isPrime(int x) {
    bool ret = true;
    for(int i = 2; i * i <= x; ++i) {
        if(x % i == 0) {
            ret = false;
            break;
        }
    }
    return ret;
}

int main() {
    int N; cin >> N;
    vector<int> ans;
    int pos = 11;
    while(ans.size() < N) {
        for(int i = pos; i <= 55555; ++i) {
            if(i % 5 == 1){
                if(isPrime(i)){
                    ans.pb(i);
                    pos = i + 1;
                    break;
                }
            }
        }
    }
    for(int i : ans) {
        cout << i << ' ';
    }
}
