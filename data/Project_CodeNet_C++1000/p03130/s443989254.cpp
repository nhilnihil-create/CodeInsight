#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main(){
    int x;
    vector<int> city(4);
    rep(i,6){
        cin >> x;
        city.at(x-1)++;
    }
    
    int cnt = 0;
    for(int c:city){
        if(c%2) cnt++;
    }
    if(cnt>2 || !city.at(0) || !city.at(1) || !city.at(2) || !city.at(3)) cout << "NO" << endl;
    else cout << "YES" << endl;
}   