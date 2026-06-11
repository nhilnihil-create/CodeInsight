#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
#include <cstdlib>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
using ll = long long;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    vector<int> a(6);
    int i, c1=0, c2=0, c3=0, c4=0;

    for(i=0; i<6; i++){
        cin >> a.at(i);

        switch(a.at(i)){
            case 1:
                c1++; break;
            case 2:
                c2++; break;
            case 3:
                c3++; break;
            case 4:
                c4++; break;
        }
    }

    if(c1==3 || c2==3 || c3==3 || c4==3) cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;
}