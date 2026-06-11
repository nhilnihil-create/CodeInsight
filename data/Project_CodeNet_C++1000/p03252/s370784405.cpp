#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s,t;cin>>s>>t;
    set<int> st;
    int a[26]{};
    fill(a,a+26,-1);
    for (int i=0;i<s.size();i++) {
        if (a[s[i]-'a']==-1) {
            if (st.count(t[i]-'a')) {
                cout<<"No"<<endl;
                return 0;
            }
            a[s[i]-'a']=t[i]-'a';
            st.insert(t[i]-'a');
        } else if (a[s[i]-'a']!=t[i]-'a') {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}