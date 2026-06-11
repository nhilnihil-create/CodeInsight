#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define ll long long

int main(){
    string s; cin >> s;
    stack<char> st;
    int ans=0;
    rep(i,s.size()){
        if(st.empty()){
            st.push(s[i]);
            continue;
        }
        char t = st.top();
        if(t!=s[i]){
            ans+=2;
            st.pop();
        }else{
            st.push(s[i]);
        }
    }
    printf("%d\n",ans);
}