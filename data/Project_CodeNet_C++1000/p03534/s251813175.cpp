#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define All(v) (v).begin(),(v).end()
typedef long long ll;

int main(){
    string S;
    cin >> S;
    int M = S.size();
    map<char,int> mp;
    rep(i,M){
        mp[S[i]]++;
    }
    int ma = max(mp['a'],max(mp['b'],mp['c']));
    int mi = min(mp['a'],min(mp['b'],mp['c']));
    if(ma-mi>=2)cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}