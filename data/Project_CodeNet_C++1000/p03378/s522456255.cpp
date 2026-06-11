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
    int n,m,x;
    cin >> n >> m >> x;
    vector<int> a(m);
    int tmp;
    vector<bool> flag(200,false);
    x--;
    rep(i,m){
        cin >> tmp;
        tmp--;
        flag[tmp] = true;
    }
    int cost0=0,costm=0;
    reps(i,x,n){
        if(flag[i] == true){
            costm++;
        }
    }
    for(int i = x; i >= 0 ;i --){
        if(flag[i] == true){
            cost0++;
        }
    }

    cout << min(cost0,costm) << endl;
    return 0;
}