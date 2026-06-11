#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

int use[13];
int ans = 0;

void DFS(int depth, vector<int> vec){
    if(depth == 13){
        vec.push_back(24);
        sort(ALL(vec));
        int pre = 0, mn = INF;
        REP(i,vec.size()){
            mn = min(mn, vec[i] - pre);
            pre = vec[i];
        }
        ans = max(ans, mn);
        return;
    }
    if(use[depth] > 0){
        if(use[depth] > 1){
            vec.emplace_back(depth);
            vec.emplace_back(24 - depth);
            DFS(depth + 1, vec);
        }else{
            vec.emplace_back(depth);
            DFS(depth + 1, vec);
            if(depth != 0){
                vec.pop_back();
                vec.emplace_back(24 - depth);
                DFS(depth + 1, vec);
            }
        }
    }else{
        DFS(depth + 1, vec);
    }
}

signed main(){
    int n;
    cin >> n;
    int d;
    REP(i,n){
        cin >> d;
        use[d]++;
    }
    REP(i,13){
        if(use[i] > 2){
            cout << 0 << endl;
            return 0;
        }
    }
    DFS(0, vector<int>(0));
    cout << ans << endl;
    return 0;
}