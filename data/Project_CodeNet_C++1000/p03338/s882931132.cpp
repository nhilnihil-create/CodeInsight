#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    string s;
    cin >> n >> s;
    
    int res = 0;
    for(int i = 0; i < n; i++){
        string first = s.substr(0, i);
        string last = s.substr(i);
        
        set<char>one;
        set<char>two;
        set<char>intersect;
        for(auto v : first){
            one.insert(v);
        }
        for(auto v: last){
            two.insert(v);
        }
        
        auto it = set_intersection(one.begin(), one.end(), two.begin(), two.end(), inserter(intersect, intersect.begin()));
        
        
        res = max(res, (int)intersect.size());
        //if(i == 3){
            //cout << first << " " << last << endl;
        //}
        one.clear();
        two.clear();
        intersect.clear();
    }
    
    cout << res << endl;
    
}
