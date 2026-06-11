#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

vector<int> vs[26],vt[26];

int main(){
    string s,t;
    cin >> s >> t;
    int n = s.length();
    rep(i,n){
        int pos = s[i] - 'a';
        vs[pos].push_back(i);
        pos = t[i] - 'a';
        vt[pos].push_back(i);
    }
    vector<bool> check(26,false);
    
    rep(i,n){
        int p1 = s[i]-'a';
        int p2 = t[i]-'a';
        if(!check[p1]){
            rep(j,vs[p1].size()){
                if(vs[p1][j] != vt[p2][j]){
                    cout << "No" << endl;
                    return 0;
                }
            }
            check[p1] = true;
        }
    }

    cout << "Yes" << endl;
    return 0;
}