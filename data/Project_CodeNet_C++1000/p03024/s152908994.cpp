#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <cctype>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    int win=0;
    rep(i,s.size()){
        if(s.at(i) == 'o') win++;
    }
    if(win+7 >= s.size()) cout << "YES" << endl;
    else cout << "NO" << endl;
}