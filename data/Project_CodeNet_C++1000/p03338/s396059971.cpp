#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;

    int ans=0;
    for(int i=0;i<s.length()-1;i++){
        int cnt=0;
        string s1=s.substr(0,i+1);
        string s2=s.substr(i+1);
        // cout << s1 + " " + s2 << endl;
        vector<bool> check1(26,false);
        vector<bool> check2(26,false);
        for(int j=0;j<s1.length();j++) check1[s1[j]-'a']=true;
        for(int j=0;j<s2.length();j++) check2[s2[j]-'a']=true;
        for(int j=0;j<26;j++) if(check1[j] && check2[j]) cnt++;
        ans=max(ans,cnt);
    }
    cout << ans << endl;
}