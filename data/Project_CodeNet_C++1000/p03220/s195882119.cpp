#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int main(){
    long long n,t,a;
    cin >> n >> t >> a;
    vector<int> h(n);
    long double tem;
    long long temp;
    a = a*1000;
    int num;
    int min = 5000000;
    int sum,ans;
    rep(i,n){
        cin >> h.at(i);
        temp = 1000*(t - 0.006*h.at(i));
        if( temp >= a) num = temp - a;
        else num = a - temp;
        if(num <= min){
            min = num;
            ans = i;
        }
    }
    cout << ans+1 << endl;
}
