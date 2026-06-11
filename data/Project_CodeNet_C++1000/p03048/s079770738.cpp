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
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    ll cnt = 0;
    rep(r, N+1){
        rep(g, N+1){
            ll sub = N - r * R - g * G;
            if(sub >= 0 && sub % B == 0) cnt++; 
        } 
    }
    cout << cnt << endl;
    return 0;
}