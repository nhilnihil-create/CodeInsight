#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <random>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include <fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using qll = queue<ll>;
using vb = vector<bool>;
using mll = map<ll, ll>;
using sll = stack<ll>;
#define REP(i,n) for(ll i(0);(i)<(n);(i)++)
#define rep(i,n) for(ll i(0);(i)<(n);(i)++)
#define ALL(a) a.begin(), a.end()
#define enld endl //* missspell check
const ll INF = 1LL << 60;

const string YES = "YES";
const string NO = "NO";

void solve(std::string S){
    string T;
    REP(i, S.length()){
        if(S[i]!= 'A')
            T.push_back(S[i]);
    }
    if(T != "KIHBR"){
        cout << NO << endl;
        return;
    }

    REP(i, S.length()-1){
        if(S.substr(i, 2)== "AA"){
            cout << NO << endl;
            return;
        }
        if(S.substr(i, 2)== "KA"){
            cout << NO << endl;
            return;
        }
        if(S.substr(i, 2)== "IA"){
            cout << NO << endl;
            return;
        }
    }
    cout << YES << endl;

}

int main(){
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}
