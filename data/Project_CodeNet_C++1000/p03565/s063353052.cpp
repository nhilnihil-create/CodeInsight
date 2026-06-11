#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin>>s>>t;
    int n = s.size(), m = t.size();
    vector<int> st;
    for(int i=0; i+m-1<n; i++) {
        int idx = i;
        bool valid = true;
        for(int j=0; j<m; j++) {
            if(s[idx] == t[j] || s[idx] == '?') {
                idx++;
            } else {
                valid = false;
                break;
            }
        }
        if(valid) {
            st.push_back(i);
        }
    }
    if((int)st.size() == 0) {
        cout<<"UNRESTORABLE\n";
        return 0;
    }
    string ans(100,'z');
    for(auto x : st) {
        string tmp = "";
        for(int i=0; i<n; i++) {
            if(i == x) {
                tmp += t;
                i+=m-1;
            } else {
                if(s[i] != '?') tmp += s[i];
                else tmp += 'a';
            }
        }
        ans = min(ans,tmp);
    }
    cout<<ans<<"\n";
    return 0;
}


