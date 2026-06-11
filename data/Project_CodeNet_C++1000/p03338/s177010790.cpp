#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    for(int i=1; i<n; i++){
        string x = s.substr(0, n-i);
        string y = s.substr(n-i, i);
        int al_x[26]={0};
        int al_y[26]={0};
        for(int j=0; j<x.length(); j++) al_x[x.at(j)-'a']++;
        for(int j=0; j<y.length(); j++) al_y[y.at(j)-'a']++;
        int count =0;
        for(int j=0; j<26; j++){
            if(al_x[j]>0 && al_y[j]>0) count++;
        }
        ans = max(ans, count);
    }
    cout << ans << endl;
    return 0;
}