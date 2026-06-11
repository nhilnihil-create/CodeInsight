#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int c = 2e5+1;
int main(void){
    string s, t;
    cin >> s >> t;
    
    int n = (int)s.size();
    map<char,int> mps,mpt;
    
    for (int i = 0; i < n; i++){
        mps[s[i]]++;
        mpt[t[i]]++;
    }
    
    vector<int> num_for_s(c);
    vector<int> num_for_t(c);
    
    for (auto p : mps){
        num_for_s[p.second]++;
    }
    
    for (auto p : mpt){
        num_for_t[p.second]++;
    }
    
    for (int i = 0; i <= c; i++){
        if (num_for_s[i] != num_for_t[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
