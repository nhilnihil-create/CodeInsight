#include <bits/stdc++.h>
 
using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i< (int) n; i++)
 
 
int main () {
    int N;

    cin >> N;

    bool can = false;
    rep(i,100){
        rep(j,100){
            if(i*7 + j*4 == N){
                can = true;
            }
        }
    }

    if(can)cout << "Yes" << endl;
    else cout << "No" << endl;



}
