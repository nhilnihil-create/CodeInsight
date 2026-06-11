#include <bits/stdc++.h>
using namespace std;
#define SELECTER(_1, _2, _3, SELECT, ...) SELECT
#define REP1(i, n) for(int i=0; (i)<(n); (i)++)
#define REP2(i, a, b) for(int i=(a); (i)<(b); (i)++)
#define REP(...) SELECTER(__VA_ARGS__, REP2, REP1,) (__VA_ARGS__)

template <class T> ostream& operator<<(ostream& os, const vector<T>& v){ os << "{"; for(size_t i=0; i<v.size(); i++) os << v[i] << (i+1==v.size() ? "" : ", "); os << "}"; return os; }
template <class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << "{" << p.first << ", " << p.second << "}"; }

int solve(int N, int K, int Q, vector<int> &A, int x){
    priority_queue<int, vector<int>, greater<int>> pq_all;
    priority_queue<int, vector<int>, greater<int>> pq;
    REP(i, N+1){
        if(A[i] < x){
            while(!pq.empty()){
                if(pq.size() >= K){
                    pq_all.push(pq.top());
                }
                pq.pop();
            }
        }else{
            pq.push(A[i]);
        }
    }
    if(pq_all.size() < Q) return 1<<30;
    int mx = 0;
    int mn = 1<<30;
    REP(i, Q){
        int tp = pq_all.top();
        pq_all.pop();
        mx = max(mx, tp);
        mn = min(mn, tp);
    }
    return mx - mn;
}

int main(){
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(N);
    REP(i, N) cin >> A[i];
    A.push_back(0);

    int ans = 1<<30;
    REP(i, N)
        ans = min(ans, solve(N, K, Q, A, A[i]));
    cout << ans << endl;
    return 0;
}