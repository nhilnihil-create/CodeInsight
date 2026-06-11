#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define PI 3.14159265358979323846264338327950L
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
char in[120];
pair<pair<string,int>,int> p[110];
int main(){
    ll r, d, x;
    cin >> r >> d >> x;
    rep(i, 10){
        x= r*x-d;
        cout << x << endl;;
    }
    return 0;
}