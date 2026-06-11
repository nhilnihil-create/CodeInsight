#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;

    stack<char> st;
    st.push(s[0]);
    int ans = 0;
    for(int i = 1; i < s.size(); i++){
        if(!st.empty() && st.top() != s[i]){
            st.pop();
            ans += 2;
        } else {
            st.push(s[i]);
        }
    }
    cout << ans << endl;
    return 0;
}