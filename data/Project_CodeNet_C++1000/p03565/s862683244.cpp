#include <bits/stdc++.h>
using namespace std;

int check(string s, string t, int idx){
    // cout<<"Cheking started for index "<<idx<<endl;
    for (int i=0; i<t.size(); i++){
        if (s[idx+i]!='?' && s[idx+i]!=t[i])return 0;
        // idx++;
    }
    // cout<<"Check is successful"<<endl;
    return 1;
}
int main()
{
    string s, t;
    cin>>s>>t;
    int n = s.size(), m = t.size();
    int flag = 0, idx=-1;
    if (m>n){
        cout<<"UNRESTORABLE"<<endl;
        return 0;
    }
    // int flag = 0;
    for (int i=0; i<n; i++){
        if (s[i]!='?' && s[i]!=t[0])continue;
        if (n-i < m)break;
        // cout<<"calling check"<<endl;
        flag = check(s, t, i);
        // cout<<"At index "<<i<<" check is "<<check<<endl;
        if (flag == 1){
            idx = i;
        }
    }
    if (idx == -1){
        cout<<"UNRESTORABLE"<<endl;
    }
    else{
        for (int j=idx; j<idx+m; j++)s[j] = t[j-idx];
            for (int j=0; j<n; j++)if (s[j]=='?')s[j]='a';

        cout<<s<<endl;
    }
}