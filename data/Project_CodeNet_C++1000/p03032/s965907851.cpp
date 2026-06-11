#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, l, r) for (ll i = (ll)l; i < (ll)(r); i++)
#define INF 1000000000000000000
#define MAX 200001
#define MOD 1000000007

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

int main(){
    int N, K;
    ll res = 0;
    cin >> N >> K;
    deque<int> dq;
    for(int i = 0; i < N; i++){
        int v;
        cin >> v;
        dq.push_back(v);
    }
    for(int i = 0; i <= K; i++){
        for(int j = 0; j <= K; j++){
            if(i + j > K || i + j > N) continue;
            auto dq_copy = dq;
            int re = K - i - j;
            vector<int> hou;
            int idx = 0;
            while(i != idx){
                hou.push_back(dq_copy.front());
                dq_copy.pop_front();
                idx++;
            }
            idx = 0;
            while(j != idx){
                hou.push_back(dq_copy.back());
                dq_copy.pop_back();
                idx++;
            }
            ll ans = 0;
            sort(hou.begin(), hou.end());
            int s = hou.size();
            for(int k = 0; k < s; k++){
                if(hou[k] >= 0  || re == 0) ans += hou[k];
                else re--;
            }
            res = max(res, ans);
        }
    }
    cout << res << endl;
}