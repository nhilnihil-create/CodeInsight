#include <bits/stdc++.h>

using namespace std;
int main(){
    int c,t,c1,t1;
    int C,T;
    pair<int,int> mejor;
    vector<pair<int,int>> x;
    cin >> c >> t;
    c1= c;
    t1 = t;
    for(int i = 0; i < c; i++){
        cin >> C >> T;
        x.push_back(make_pair(C,T));
    }
    mejor = x[0];
    for(int i = 0; i < x.size(); i++){
        if(x[i].first <= mejor.first&& x[i].second <= t) mejor = x[i];    
    }

    if(mejor.second > t) cout << "TLE";
    else cout << mejor.first;
    return 0;
}
