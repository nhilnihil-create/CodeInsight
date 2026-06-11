#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
 
int main(){
    double n, t, a; cin >> n >> t >> a;
    vector<double> h(n);
    rep(i, n){cin >> h[i];}
    double temp = 100000;
    int place = 0;
    rep(i, n){
        double diff = abs(a - (t - h[i] * 0.006));
        if (diff < temp){
            temp = diff;
            place = i+1;
        }
    }
    cout << place << endl;
}