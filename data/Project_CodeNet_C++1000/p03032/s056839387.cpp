#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N,K;
    cin >> N >> K;
    vector<int> vec(N);
    rep(i,N){
        cin >> vec[i];
    }
    int ans = 0;
    for (int i = 0; i <= N - 1; i++){
        for (int j = 0; j <= N - i; j++){
            int sub_ans = 0;
            priority_queue<int> q;
            rep(k,i){
                sub_ans += vec[k];
                q.push(vec[k] * -1);
            }
            rep(l,j){
                sub_ans += vec[N - 1 - l];
                q.push(vec[N - 1 - l] * -1);
            }
            if (i + j > K){
                continue;
            }
            else{
                int lim = K - i - j;
                rep(m,lim){
                    if (q.size() == 0){
                        break;
                    }
                    if (q.top() >= 0){
                        sub_ans += q.top();
                        q.pop();
                    }
                }
            }
            ans = max(ans,sub_ans);
        }
    }
    cout << ans << endl;
}

