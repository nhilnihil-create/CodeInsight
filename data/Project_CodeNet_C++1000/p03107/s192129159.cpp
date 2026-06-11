#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)


int main(){
    string s;
    cin>>s;
    stack<char> st;
    rep(i,(int)s.size()){
        if(st.empty()) st.push(s[i]);
        else{
            if(s[i]!=st.top()) st.pop();
            else st.push(s[i]);
        }
    }
    cout<<(int)s.size()-(int)st.size()<<endl;
}