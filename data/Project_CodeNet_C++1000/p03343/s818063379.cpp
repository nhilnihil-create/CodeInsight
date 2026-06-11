#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int inf = 1 << 30;
int N, K, Q;
int A[2010];

int solve(){
    int ans = inf;
    vector<int> vs;
    for(int i = 0; i < N; i++){
        vs.push_back(A[i]);
    }
    sort(vs.begin(), vs.end());
    vs.erase(unique(vs.begin(), vs.end()), vs.end());
    for(auto u : vs){
        vector<int> val;
        vector<int> sec;
        for(int i = 0; i < N; i++){
            if(A[i] >= u) sec.push_back(A[i]);
            if(A[i] < u || i == N - 1){
                sort(sec.begin(), sec.end());
                int size = sec.size();
                for(int j = 0; j <= size - K; j++){
                    val.push_back(sec[j]);
                }
                sec.clear();
            }
        }
        if(val.size() >= Q){
            sort(val.begin(), val.end());
            ans = min(ans, val[Q - 1] - val[0]);
        }
    }
    return ans;
}

void init(){
    cin >> N >> K >> Q;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
}

int main(){
    init();
    cout << solve() << endl;
    return 0;
}