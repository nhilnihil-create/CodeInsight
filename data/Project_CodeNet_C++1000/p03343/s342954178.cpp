#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <bitset>
#include <set>
using namespace std;


int N, K, Q;
vector<int> A;

int solve(int idx){
    int mn = A[idx];
    vector<vector<int>> v;
    vector<int> cur;
    for(int i=1; i<=N; i++){
        if(A[i] < mn){
            if(!cur.empty()){
                v.push_back(cur);
                cur.clear();
            }
        }else{
            cur.push_back(A[i]);
        }
    }
    if(!cur.empty())
        v.push_back(cur);

    vector<int> vv;
    for(auto x : v){
        if(x.size() < K) continue;
        sort(x.begin(), x.end());
        for(int i=0; i<=x.size()-K; i++){
            vv.push_back(x[i]);
        }
    }
    if(vv.size() < Q)
        return 1<<30;
    sort(vv.begin(), vv.end());
    return vv[Q-1] - vv[0];
}

int main(){
    cin >> N >> K >> Q;
    A.resize(N+2, 0);
    for(int i=1; i<=N; i++)
        cin >> A[i];

    int ans = 1<<30;
    for(int i=1; i<=N; i++)
        ans = min(ans, solve(i));
    cout << ans << endl;
    return 0;
}
