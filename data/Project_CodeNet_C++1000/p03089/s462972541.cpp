#include <bits/stdc++.h>
using namespace std;

//#define int long long
struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;
using intpair = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()

signed main(){
    int n; cin >> n;
    vector<int> b(n);
    rep(i,n) cin >> b[i];
    
    stack<int> answer;
    
    rep(i,n){
        for(int j = b.size()-1; j >= 0; j--){
            if(b[j] != j+1) continue;
            b.erase(b.begin()+j);
            answer.push(j+1);
            break;
        }
    }
    
    if(b.empty()){
        while(!answer.empty()){
            cout << answer.top() << endl;
            answer.pop();
        }
    }else{
        cout << -1 << endl;
    }
}