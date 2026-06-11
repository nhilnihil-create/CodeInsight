#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    map<char,int> mp;
    char c;
    for(int i=0;i<n;i++){
        cin >> c;
        mp[c]++;
    }
    int ans=0;
    for(auto u:mp)ans++;
    if(ans==3)cout << "Three";
    else cout << "Four";
}