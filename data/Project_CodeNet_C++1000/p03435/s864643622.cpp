#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};



int main() {
    int c[3][3];
    rep(i,3) rep(j,3) cin >> c[i][j];

    bool ok = true;
    int sum = 0;
    rep(i,3) rep(j,3){
        sum += c[i][j];
    }
    if(sum % 3 != 0){cout << "No" << endl; return 0;}
    sum /= 3;
    if(c[0][0]+c[1][1]+c[2][2]!= sum) ok = false;
    if(c[0][0]+c[2][1]+c[1][2] != sum) ok = false;
    if(c[1][0]+c[0][1]+c[2][2] != sum) ok = false;
    if(c[1][0]+c[2][1]+c[0][2] != sum) ok = false;
    if(c[2][0]+c[1][1]+c[0][2] != sum) ok = false;
    if(c[2][0]+c[0][1]+c[1][2] != sum) ok = false;

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}
