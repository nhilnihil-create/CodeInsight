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

int main(){
    string s;
    cin >> s;
    int len = s.length()-7;

    rep(i,7){
        if( s.substr(0,i) + s.substr(i+len,7-i) == "keyence"){
            cout << "YES"<< endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}