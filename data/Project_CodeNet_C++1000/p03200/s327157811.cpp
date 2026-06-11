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
    string S;
    cin >> S;
    int N = (int)S.size();
    int W_cnt = 0;
    ll cnt = 0;
    rep(i, N){
        if(S.at(i) == 'W'){
            cnt += (i - W_cnt);
            W_cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}