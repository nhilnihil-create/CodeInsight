#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define int long long
#define all(a) a.begin(), a.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e15;

int digitSum(int n){
   int res = 0;
   while(n){
       res += n % 10;
       n /= 10;
   }
   return res;
}

void solve(){
    int cnt = 0;
    for(int i = 1; i <= 1000000; i++){
        bool f = true;
        for(int j = i + 1; j <= 10000000; j++){
            if(i * digitSum(j) > j * digitSum(i)){
                f = false; break;
            }
        }
        if(f){
            cout << ++cnt << " " << i << endl;
        }
    }
}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    vector<int> cand;
    set<int> st;
    for(int j = 0; j <= 12; j++){
        for(int i = 1; i <= 999; i++){
            int now = i;
            for(int k = 0; k < j; k++){
                now = now * 10 + 9;
            }
            if(st.count(now)) continue;            
            cand.push_back(now);
            st.insert(now);
        }
    }
    int cnt = 0;
    rep(i, 0, cand.size()){
        bool f = true;
        rep(j, i + 1, cand.size()){
            if(cand[i] * digitSum(cand[j]) > cand[j] * digitSum(cand[i])){
                f = false; break;
            }
        }
        if(f){
            cout << cand[i] << endl;
            cnt++;
            if(cnt == k) break;
        }
    }
}