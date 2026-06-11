#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main(){
    int n;    cin >> n;
    double t, a; cin >> t >> a;
    vector<double> h(n);
    rep(i, n) cin >> h[i];

    double dis = 1000.0, tem = 0.0;
    int ids = 0;
    rep(i, n){
        tem = t - h[i]*0.006;
        if(abs(a - tem) < dis){
            dis = abs(a - tem); ids = i+1;
        }
    }
    cout << ids << endl;
    return 0;
}