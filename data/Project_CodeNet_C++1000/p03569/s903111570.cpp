#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
// ctrl + cで実行


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    string s;
    cin>>s;
    int n = s.size();
    int cnt[26]={};
    string t = "";
    for(int i=0;i<n;i++){
        cnt[s[i]-'a']++;
        if(s[i] != 'x') t += s[i];
    }
    for(int i=0;i<t.size();i++){
        if(t[i] != t[t.size()-1-i]){
            cout << -1 << endl;
            return 0;
        }
    }
    int l = 0, r = n-1;
    int ans = 0;
    while(r>l){
        if(s[l]!=s[r]){
            ans++;
            if(s[l]=='x') l++;
            else r--;
        }
        else{
            r--;
            l++;
        }
    }
    cout << ans << endl;

}