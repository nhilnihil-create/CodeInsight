#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

#define REP(i,n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;
using ll = long long;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    //write here
    ll N,P;
    cin >> N >> P;
    ll count = 2;
    ll res = 1;
    if (N == 1) {
        cout << P << endl;
        return 0;
    }

    while(1){
        bool is_down = false;
        ll tmp = 1;
        for(int i = 0; i < N;i = i + 1) {
            tmp *= count;
            if(tmp > P) {
                is_down = true;
                break;
            }
        }
        if (tmp > P || is_down)
            break;
        //  if(P % count == 0)
        //     P /= count;
        if (P % tmp == 0) {
            res = count;

        }

        count += 1;
    }

    cout << res<< endl;
    return 0;
}