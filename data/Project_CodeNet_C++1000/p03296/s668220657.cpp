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
    vector<int> consnum;
    vector<int> v(n);
    cin >> v[0];
    int count = 1;
    REP(i,1,n){
        cin >> v[i];
        if(v[i-1]==v[i]){
            count++;
        }else{
            consnum.push_back(count);
            count = 1;
        }
    }
    consnum.push_back(count);

    int ans = 0;
    for(int val : consnum){
        if(val>=2){
            ans += val/2;
        }
    }
    cout << ans << endl;

    return 0;
}