#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n;
    cin >> n;
    vector<int> t(n),x(n),y(n);
    rep(i,n){
        cin >> t[i] >> x[i] >> y[i];
    }
    int nowx = 0, nowy = 0;
    int dist = 0;
    int nowt = 0;
    rep(i,n){
        dist = abs(x[i] + y[i] - (nowx + nowy));
        if(dist > t[i]-nowt){
            cout << "No" << endl;
            return 0;
        }
        if(dist%2 == (t[i]-nowt)%2){
            nowt = t[i];
            nowx = x[i];
            nowy = y[i];
        }else{
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}