#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    set<string> st;
    string temp;
    cin >> temp;
    st.insert(temp);
    bool ok = true;
    rep(i,n-1){
        string s;
        cin >> s;
        st.insert(s);
        if(s.front() != temp.back()) ok = false;
        temp = s;
    }

    if(st.size()!=n || !ok) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}