#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;  cin >> n;
    
    map<string ,int > mp;
    string s;   cin >> s;
    mp[s]++;
    
    for(int i=0;i<n-1;i++){
        string t;   cin >> t;
        mp[t]++;
        if(s[s.size()-1]!=t[0]){
            cout << "No" << endl;
            return 0;
        }
        s = t;
    }
    
    if(mp.size()!=n){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    
    return 0;
}
