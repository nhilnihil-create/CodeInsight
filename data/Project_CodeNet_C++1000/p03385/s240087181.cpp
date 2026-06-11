#include <bits/stdc++.h>
using namespace std;
int main(){
    string s; cin >> s;
    map<char,int> mp;
    for(int i=0;i<s.size();++i){
        mp[s[i]]++;
    }
    if(mp.size() == 3) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}