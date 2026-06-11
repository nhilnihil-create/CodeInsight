#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <deque>
using namespace std;

#define next '\n'
#define sp " "
#define print(x) cout << (x)
#define println(x) cout << (x) << next
#define stop return(0)
#define rep(i, n) for(int (i) = (0); (i) < (n); (++i))
#define FOR(i, start, end) for(int (i) = (start); (i) < (end); (++i))
#define foreach(elem, _list) for(auto& (elem) : (_list))
#define debug(_list) foreach(e, _list){ cout << e << sp; } cout << next
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr)
#define size(s) (s).size()
#define all(vec) (vec).begin(), (vec).end()
#define pb(e) push_back(e);
#define INF 1e+8
#define PI acos(-1)
#define TAU PI * 2
using ll = long long;
using ull = unsigned long long;
ll MOD = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n){
        cin >> a[i];
    }

    int ans = 0;
    int current = a[0];
    int cnt = 0;
    rep(i, n){
        if(current == a[i]){
            cnt++;
        }else{
            ans += cnt / 2;
            current = a[i];
            cnt = 1;
        }
    }

    ans += cnt / 2;

    println(ans);
}