#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<double> x(n);
    vector<string> u(n);
    rep(i,n){
        cin >> x[i] >> u[i];
    }
    double b = 0;
    int j = 0;
    rep(i,n){
        if(u[i]  == "BTC") b += x[i];
        else if(u[i] == "JPY") j += x[i];
    }
    double sum = b*380000 + j;
    cout << fixed << setprecision(5) << sum <<endl;
}