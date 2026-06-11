#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define pint pair<int, int>
#define plong pair<long, long>

int main() {
    int N;
    cin>>N;
    vvi T(N);
    vi C(N);
    REP(i, 0, N-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        T[a].push_back(b);
        T[b].push_back(a);
    }
    REP(i, 0, N) cin >> C[i];
    sort(C.rbegin(), C.rend());
    int leaf = 0, count = 0;

    vi ans(N, 0);
    queue<int> que;
    
    while(T[leaf].size() != 1) leaf++;
    que.push(leaf); ans[leaf] = C[count];
    count++;
    while(!que.empty()){
       auto cur = que.front(); que.pop();
       for(int next: T[cur]){
           if(ans[next] == 0){
               que.push(next);
               ans[next] = C[count];
               count++;
           }
        }
    }
    cout << accumulate(C.begin()+1, C.end(), 0) << endl;
    REP(i, 0, N) cout << ans[i] << " ";
    cout << endl;
}