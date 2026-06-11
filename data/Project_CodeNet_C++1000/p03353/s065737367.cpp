#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string,int> mp;
    string s;
    int k;
    cin >> s >> k;
    for(int i=0;i<s.length();i++){
        string t;
        for(int j=i;j<min(i+k,(int)s.length());j++){
            t.push_back(s[j]);
            mp[t]++;
        }
    }
    int c=0;
    for(auto u:mp){
        c++;
        if(c==k){
            cout << u.first << endl;
            return 0;
        }
    }
}