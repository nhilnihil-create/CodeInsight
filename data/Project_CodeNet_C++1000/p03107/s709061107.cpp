#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    string s; cin >> s;
    stack<int> st;
    for(int i = 0; i < s.size(); ++i){
        if(st.empty()) {
            st.push(s[i] - '0');
            continue;
        }
        int c = st.top();
        int now = s[i] - '0';
        if(c ^ now) st.pop();
        else st.push(now);
    }
    cout << s.size() - st.size() << endl;
}