#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
string addDigit(string s){
    while(s.size() < 6){
        s = "0"+s;
    }
    return s;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> inp;
    map<int,vector<int>> mp;
    for(int i = 0; i < m; ++i){
        int p,y;
        cin >> p >> y;
        inp.push_back(make_pair(p,y));
        mp[p].push_back(y);
    }
    map<pair<int,int>, string> mp2;
    for(auto it = mp.begin(); it != mp.end(); ++it){
        vector<int> vec = it->second;
        sort(vec.begin(),vec.end());
        string s = addDigit(to_string(it->first));
        for(int i = 0; i < vec.size(); ++i){
            string t = addDigit(to_string(i+1));
            mp2[make_pair(it->first,vec[i])] = s+t;
        }
    }
    for(pair<int,int> p:inp){
        cout << mp2[p] << endl;
    }
    return 0;
}