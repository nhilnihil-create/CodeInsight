#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <tuple>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <list>

using ll = long long;
using ld = long double;
using namespace std;
const int INF = 1e9+100;
const ll INF64 = 7e18l;
const int mod = 1000000007;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(a) (a).begin(), (a).end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main(){
    FIN;
    char c;
    string s;
    int y=0,m=0;
    for(int i=3;i>=0;i--){
        cin >> c;
        s = c;
        y += pow(10,i) * stoi(s);
    }
    if(y < 2019){ cout << "Heisei" << endl; return 0;}
    if(y > 2019){ cout << "TBD" << endl; return 0;}
    cin >> c;

    for(int i=1;i>=0;i--){
        cin >> c;
        s = c;
        m += pow(10,i) * stoi(s);
    }
    if(m <= 4){cout << "Heisei" << endl; return 0;}
    else {cout << "TBD" << endl; return 0;}


    return 0;
}

