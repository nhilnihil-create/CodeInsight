#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    sort(a.begin(),a.end(),greater<int>());
    int alice=0,bob=0;
    rep(i,n){
        if(i % 2 == 0)alice += a[i];
        else bob += a[i];
    }
    cout << alice -bob <<endl;

    return 0;
}