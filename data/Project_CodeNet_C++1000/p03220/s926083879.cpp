#include <bits/stdc++.h>
using namespace std;
#define ll long long int;
#define P pair<int, int>;
#define rep(i, n) for(int (i) = 0; i < (n); i++)

int main(){
    int n, t, a;
    cin >> n >> t >> a;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    int out = 0;
    double min = INT_MAX;
    rep(i, n){
        double temp = abs(t - h[i] * 0.006 - a);
        if(min > temp){
            min = temp;
            out = i + 1;
        }
    }
    cout << out << endl;
}