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
    sort(C.begin(), C.end());
    int leaf = 0, count = 0;

    vi ans(N, 0);
    stack<int> stk;
    vi Map(N, 0);

    while(T[leaf].size() != 1) leaf++;
    stk.push(leaf); Map[leaf] = 1;
    while(!stk.empty()){
        bool isLeaf = true;
        auto cur = stk.top();
        for(int next: T[cur]){
            if(Map[next] == 0){
                stk.push(next);
                Map[next] = 1;
                isLeaf = false;
            }
        }
        if(isLeaf){
            ans[cur] = C[count];
            count++;
            stk.pop();
        }
    }
    cout << accumulate(C.begin(), C.end()-1, 0) << endl;
    REP(i, 0, N) cout << ans[i] << " ";
    cout << endl;
}