#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<pair<pair<string,int>,int>> p;
    
    for (int i = 0; i < n; i++){
        string temp;
        int t;
        cin >> temp >> t;
        p.emplace_back(make_pair(make_pair(temp,-t),i));
    }
    
    sort(p.begin(),p.end());
    for (auto a : p){
        cout << a.second + 1 << endl;
    }
}