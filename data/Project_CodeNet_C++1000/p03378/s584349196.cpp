
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()


int main(){
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(m);
    rep(i,m) cin >> a[i];

    int sum1=0,sum2=0;
    rep(i,m){
        if(a.at(i) < x){
            sum1 ++;
        }
        else if(a.at(i) > x){
            sum2 ++;
        }
    }
    cout << min(sum1,sum2) << endl;

}