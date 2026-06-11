#include <iostream>
#include <utility>
#include <queue>
#include <memory>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)

using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main(){
    string s;
    cin >> s;

    if((s[0] == s[1] && s[1] == s[2]) || (s[1] == s[2]  && s[2] == s[3])){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}