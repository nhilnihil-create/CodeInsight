#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int solver(int N, int K, vector<int> Vec){
    deque<int> V;
    rep(i, N){
        V.push_back(Vec[i]);
    }

    int ans = 0;
    for(int i = 0; i <= K; i++){
        for(int j = 0; j + i <= K; j++){
            //i番目まで左から、j番目まで右から取り出す　残りは詰めるパート
            deque<int> tmp = V;
            vector<int> t_ans;
            // cout << i << " " << j << endl;
            rep(l, i){
                if(tmp.size() == 0)break;
                t_ans.push_back(tmp[0]);
                tmp.pop_front();
            }
            rep(r, j){
                if(tmp.size() == 0)break;
                t_ans.push_back(tmp[tmp.size() - 1]);
                tmp.pop_back();
            }
            sort(all(t_ans));
            int loop = min(K - i - j, (int)t_ans.size());
            rep(k, loop){
                if(t_ans[k] < 0)t_ans[k] = 0;
            }
            int sum = 0;
            rep(k, t_ans.size())sum += t_ans[k];
            ans = max(ans, sum);
        }
    }
    return ans;
}


int main(){
    int N, K; cin >> N >> K;
    vector<int> V(N);
    rep(i, N) cin >> V[i];
    cout << solver(N, K, V) << endl;
}