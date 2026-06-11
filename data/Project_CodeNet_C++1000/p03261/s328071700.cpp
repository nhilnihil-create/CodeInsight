#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string,int> mp;
    string s,t;
    int n;
    cin >> n;
    cin >> t;
    mp[t]++;
    int flag=0;
    for(int i=1;i<n;i++){
        cin >> s;
        if(s[0]!=t[t.length()-1] || mp[s]>0)flag++;
        mp[s]++;
        t=s;
    }
    if(flag>0)cout << "No" << endl;
    else cout << "Yes" << endl;
}