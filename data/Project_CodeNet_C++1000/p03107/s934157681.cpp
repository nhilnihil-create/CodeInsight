#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;


int main(){
    string s; cin >> s;
    stack<char> st;
    int ans = 0;
    rep(i, s.length()){
        if(st.empty()){
            st.push(s[i]);
        }else{
            int t = st.top();
            if(t != s[i]){
                st.pop();
                ans += 2;
            }
            else st.push(s[i]);
        }
    }
    cout << ans << endl;
    
}