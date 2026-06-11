#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
     int N,T;
    cin >> N >> T;
    vector<int>c(N);
    vector<int>t(N);
    int a=30000;
    rep(i,N){
        cin >> c.at(i) >> t.at(i);
        if(t.at(i)<=T){
            a=min(a,c.at(i));
        }
    }
    if(a==30000)cout << "TLE" << endl;
    else {
    cout << a << endl;}
 
}