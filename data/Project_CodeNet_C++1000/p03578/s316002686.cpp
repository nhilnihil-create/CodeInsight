#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N;
    cin >> N;
    map<ll, int> mp_D;
    rep(i, N){
        ll a;
        cin >> a;
        mp_D[a]++;
    }
    int M;
    cin >> M;
    map<ll, int> mp_T;
    rep(i, M){
        ll a;
        cin >> a;
        mp_T[a]++;
    }
    bool is = true;
    for(auto mp : mp_T){
        if(mp_D.count(mp.first) == 0){
            is = false;
            break;
        }
        if(mp_D[mp.first] < mp.second){
            is = false;
            break;
        }
    }
    if(is) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}