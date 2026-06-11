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
const int INF = 1e12;

int change_to_i(string s){
   stringstream ss; int k;
   ss<<s; ss>>k;
   return k;
}

string change_to_s(int n){
   stringstream ss; ss<<n;
   return ss.str();
}

int getDigitSum(int n){
   int res = 0;
   while(n){
       res += n % 10;
       n /= 10;
   }
   return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    vector<int> ans;
    vector<int> cand;    
    set<int> st;
    rep(i, 1, 1000){
        cand.push_back(i);
        st.insert(i);
    }
    rep(i, 4, 16){
        string s = "";
        rep(j, 0, i - 3) s += "9";
        rep(j, 1, 1000){
            string t = change_to_s(j);
            t += s;
            int tmp = change_to_i(t);
            if(!st.count(tmp)){
                cand.push_back(tmp);
                st.insert(tmp);
            }
        }
    }
    rep(i, 0, cand.size()){
        int now = getDigitSum(cand[i]);
        bool f = true;
        rep(j, i + 1, cand.size()){
            int tmp = getDigitSum(cand[j]);
            if(cand[i] * tmp > cand[j] * now){
                f = false;
                break;
            }
        }
        if(f){
            ans.push_back(cand[i]);    
        }
    }
    rep(i, 0, k){
        cout << ans[i] << endl;
    }
}