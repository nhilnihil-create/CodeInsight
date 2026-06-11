#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (1000000007)
#define INF (1e9)
#define INFL (1e18)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>using arr=vector<vector<T>>;
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int n, k;
deque<int> v;
int Plus=0, Minus=0;
int ans = 0;

void dfs(deque<int> dq, priority_queue<int, vector<int>, greater<int>> pq, int sum, int plus_i, int minus_i, int plus_o, int minus_o, int step){
    chmax(ans, sum);
    if(step==k) return;

    if(dq.empty()){
        if(pq.top()>=0) return;
        else{
            int t = pq.top();
            dq.push_front(t);
            pq.pop();
            dfs(dq, pq, sum-t, plus_i, minus_i+1, plus_o, minus_o-1, step+1);

            dq.pop_front();
            dq.push_back(t);
            dfs(dq, pq, sum-t, plus_i, minus_i+1, plus_o, minus_o-1, step+1);
        }
    }else{
        if(plus_i == 0){
            if(pq.top()>=0) return;
            else{
                int t = pq.top();
                dq.push_front(t);
                pq.pop();
                dfs(dq, pq, sum-t, plus_i, minus_i+1, plus_o, minus_o-1, step+1);

                dq.pop_front();
                dq.push_back(t);
                dfs(dq, pq, sum-t, plus_i, minus_i+1, plus_o, minus_o-1, step+1);
            }
        }else{
            if(pq.top()>=0) {
                priority_queue<int, vector<int>, greater<int>> tq = pq;
                int t = dq.front(); dq.pop_front();
                tq.push(t);
                dfs(dq, tq, sum+t, plus_i-(t>=0), minus_i-(t<0), plus_o+(t>=0), minus_o+(t<0), step+1);
                dq.push_front(t);

                t = dq.back(); dq.pop_back();
                pq.push(t);
                dfs(dq, pq, sum+t, plus_i-(t>=0), minus_i-(t<0), plus_o+(t>=0), minus_o+(t<0), step+1);
                dq.push_back(t);
            }else{
                int t = pq.top();
                dq.push_front(t);
                pq.pop();
                dfs(dq, pq, sum-t, plus_i, minus_i+1, plus_o, minus_o-1, step+1);

                dq.pop_front();
                dq.push_back(t);
                dfs(dq, pq, sum-t, plus_i, minus_i+1, plus_o, minus_o-1, step+1);
                dq.pop_back();

                priority_queue<int, vector<int>, greater<int>> tq = pq;
                t = dq.front(); dq.pop_front();
                tq.push(t);
                dfs(dq, tq, sum+t, plus_i-(t>=0), minus_i-(t<0), plus_o+(t>=0), minus_o+(t<0), step+1);
                dq.push_front(t);

                t = dq.back(); dq.pop_back();
                pq.push(t);
                dfs(dq, pq, sum+t, plus_i-(t>=0), minus_i-(t<0), plus_o+(t>=0), minus_o+(t<0), step+1);
                dq.push_back(t);
            }
        }

    }
}

int main()
{
    cin >> n >> k;
    rep(i, n){
        int a; cin >> a;
        v.push_back(a);
    }

    FOR(i, 1, k+1){
        if(i>n) break;
        rep(left, i+1){
            deque<int> w = v;
            int right = i - left;
            vector<int> s;
            rep(l, left) {s.push_back(v.front()); v.pop_front();}
            rep(r, right) {s.push_back(v.back()); v.pop_back();}
            sort(s.rbegin(), s.rend());
            // prvec(s);
            rep(l, k-i) {
                if(s.empty() || s.back()>0) break;
                s.pop_back();
            }
            int sum = 0;
            rep(l, s.size()) sum += s[l];
            chmax(ans, sum);
            v = w;
        }
    }

    pr(ans);
    return 0;}