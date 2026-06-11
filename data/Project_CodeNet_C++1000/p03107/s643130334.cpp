#include <bits/stdc++.h>
     
using namespace std;
     
int main() {
    string s;
    cin >> s;
    stack<int> st;
    int no_rem = 0;
    for (int i = 0; i < s.length(); i++) {
        if (!st.empty()) {
          	if (st.top() == 1 && s[i] == '0') {
                no_rem++;
                st.pop();
            }
            else if (st.top() == 0 && s[i] == '1') {
                no_rem++;
                st.pop();
            } 
            else {
                st.push(s[i] - '0');
            }
        } else {
            st.push(s[i] - '0');
        }
    }
    cout << no_rem * 2;
}