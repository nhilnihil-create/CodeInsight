#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
//const int MOD = 1e9+7;


int main(){
    string s;
    cin >> s;
    stack<char> st;
    st.push(s[0]);

    int ans = 0;
    for(int i=1; i<(int)s.length(); ++i){
        if(st.size() && ((st.top() == '1' && s[i]=='0') || (st.top() == '0' && s[i]=='1'))){
            st.pop();
            ans+=2;
        }
        else{
            st.push(s[i]);
        }
    }
    cout << ans;
}
