#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin>>s>>t;
    int n = s.size(), m = t.size();
    int st = -1;
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
            st = i;
        }
    }
    if(st == -1) {
        cout<<"UNRESTORABLE\n";
        return 0;
    }

    string tmp = "";
    for(int i=0; i<n; i++) {
        if(i == st) {
            tmp += t;
            i+=m-1;
        } else {
            if(s[i] != '?') tmp += s[i];
            else tmp += 'a';
        }
    }
    cout<<tmp<<"\n";
    return 0;
}


