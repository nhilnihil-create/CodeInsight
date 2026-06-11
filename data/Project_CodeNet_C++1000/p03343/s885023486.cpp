#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;

int main(){

    int N, K, Q;
    cin >> N >> K >> Q;

    vector<int> A(N + 1);
    rep(i, N)cin >> A[i];
    A[N] = 0;

    int ans = 1000000000;
    rep(loop1, N){

        int minimum = A[loop1];
        vector<int> canuse;
        
        {
            int l = 0;
            rep(r, N + 1){
                if(A[r] < minimum){
                    if(r - l >= K){
                        priority_queue<int, vector<int>, greater<int>> que;
                        for(int i = l; i < r; i++)que.push(A[i]);
                        rep(i, r - l - K + 1){
                            canuse.push_back(que.top());
                            que.pop();
                        }
                    }
                    l = r + 1;
                }
            }
        }

        if((int)canuse.size() >= Q){
            sort(all(canuse));
            chmin(ans, canuse[Q - 1] - minimum);
        }
        
    }

    cout << ans << endl;
    return 0;

}