#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    string s;
    map<string,int> mp;
    rep(i,n){ 
        cin >> s;
        mp[s]++;
    }

    if(mp["G"] > 0 && mp["W"] > 0 && mp["Y"] > 0 && mp["P"] > 0){
        cout << "Four" << endl;
    }else{
        cout << "Three" << endl;
    }

    return 0;
}