#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    int n, k;
    cin >> n >> k;
    deque<int> dq;
    rep(i,n){
        int v;
        cin >> v;
        dq.push_back(v);
    }

    int lim = k;
    int ans = 0;
    while(k){
        int ope = k, cnt = lim-k;
        priority_queue<int, vector<int>, greater<int>> pq;
        deque<int> dq_tmp = dq;
        int sum = 0;
        rep(i, ope){
            if (dq_tmp.empty()) break;
            int v = dq_tmp.front(); dq_tmp.pop_front();
            sum += v;
            pq.push(v);
            ans = max(ans, sum);
        }
        for(int i = 0; i < cnt; i++){
            int sum_tmp = sum;
            priority_queue<int, vector<int>, greater<int>> pq_tmp = pq;
            deque<int> dq_tmp_tmp = dq_tmp;
            for(int j = 0; j < i; j++){
                if (dq_tmp_tmp.empty()) break;
                int v = dq_tmp_tmp.back(); dq_tmp_tmp.pop_back();
                pq_tmp.push(v);
                sum_tmp += v;
                ans = max(ans, sum_tmp);
            }
            for(int j = i; j < cnt; j++){
                if (pq_tmp.empty() || pq_tmp.top() > 0) break;
                int v = pq_tmp.top(); pq_tmp.pop();
                sum_tmp += v * -1;
                ans = max(ans, sum_tmp);
            }
        }
        k--;
    }
    cout << ans << endl;
    return 0;
}