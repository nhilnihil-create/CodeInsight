// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

typedef tuple<ll, int, int, int> T;

int main(){
    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<ll> A(X), B(Y), C(Z);
    rep(i, X) cin >> A[i];
    rep(i, Y) cin >> B[i];
    rep(i, Z) cin >> C[i];

    sort(all(A));
    reverse(all(A));
    sort(all(B));
    reverse(all(B));
    sort(all(C));
    reverse(all(C));

    priority_queue<T> que;
    set<T> added;
    T t(A[0] + B[0] + C[0], 0, 0, 0);
    que.push(t);
    added.insert(t);

    rep(tmp, K){
        T t = que.top();
        que.pop();
        cout << get<0>(t) << endl;
        int i = get<1>(t), j = get<2>(t), k = get<3>(t);
        if(i + 1 < X){
            T u(A[i + 1] + B[j] + C[k], i + 1, j, k);
            if(!added.count(u)){
                que.push(u);
                added.insert(u);
            } 
        } 
        if(j + 1 < Y){
            T u(A[i] + B[j + 1] + C[k], i, j + 1, k);
            if(!added.count(u)){
                que.push(u);
                added.insert(u);
            } 
        } 
        if(k + 1 < Z){
            T u(A[i] + B[j] + C[k + 1], i, j, k + 1);
            if(!added.count(u)){
                que.push(u);
                added.insert(u);
            } 
        } 
    }
}