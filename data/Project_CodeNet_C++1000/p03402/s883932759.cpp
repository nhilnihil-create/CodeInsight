//#include "pch.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <limits.h>
#include <string>
#include <cmath>

using namespace std;

#define rip(i, n, s) for (int i = (s);i < (int)( n ); i++)
#define mp make_pair
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef pair<ll,ll> P;

int main(){
    int a,b;
    cin >> a >> b;
    printf("100 100\n");
    string  s;
    rip(i,50,0){
        s += '#';
    }
    rip(i,100,50){
        s += '.';
    }
    vector<string> ans(100,s);
    rip(i,a-1,0){
        ans[i%50*2][i/50*2] = '.';
    }
    rip(i,b-1,0){
        ans[i%50*2][99 - i/50*2] = '#';
    }
    rip(i,100,0){
        cout << ans[i] << endl;
   }
}