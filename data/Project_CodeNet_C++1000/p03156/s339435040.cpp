#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include<limits.h>
#include<iomanip>
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, m, n) for(int i = m; i < n; i++)
#define ALL(v) v.begin(),v.end()
#define RALL(v) v.rbegin(),v.rend()
#define check(v) rep(i,v.size()) cout << v[i] << " ";\
cout << endl
#define INF 1e8
typedef long long ll;
using namespace std;
//オーバーフローに気をつけろよおおおおおお
//確認忘れるなよおおおおおお

int main() {
    int n; cin >> n;
    int a, b; cin >> a >> b;
    int fi=0, se=0, th=0;
    rep(i,n){
        int num; cin >> num;
        if(num<=a) fi++;
        else if(num<=b) se++;
        else th++;
    }
    cout << min({fi,se,th}) << endl;

    return 0;
}