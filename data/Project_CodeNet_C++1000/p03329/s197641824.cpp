#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
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
    vector<int> d(N+1, 1000000);
    d[0] = 0;
    
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, 0));

    while (!que.empty()){
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int pow6 = 1; pow6 <= N; pow6 *= 6){
            if (v+pow6 > N) break;
            if (d[v+pow6] > d[p.second] + 1){
                d[v+pow6] = d[p.second]+1;
                que.push(P(d[v+pow6], v+pow6));
            }
        }
        for (int pow9 = 1; pow9 <= N; pow9 *= 9){
            if (v+pow9 > N) break;
            if (d[v+pow9] > d[p.second] + 1){
                d[v+pow9] = d[p.second]+1;
                que.push(P(d[v+pow9], v+pow9));
            }
        }
    }

    cout << d[N] << endl;
}