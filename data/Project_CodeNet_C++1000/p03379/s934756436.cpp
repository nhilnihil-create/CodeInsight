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
    vector<int> x(n),tmp(n);
    rep(i,n){
        cin >> x[i];
        tmp[i] = x[i];
    }
    sort(tmp.begin(),tmp.end(),greater<int>());

    //for (auto e: tmp) cout << e << endl;
    // cout << tmp[n/2-1] << " " << tmp[n/2] << endl;
    // cout << endl;
    rep(i,n){
        if(x[i] <= tmp[n/2]){
            cout << tmp[n/2-1] << endl;
        }else{
            cout << tmp[n/2] << endl;
        }
    }

    return 0;
}
