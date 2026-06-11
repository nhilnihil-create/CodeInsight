#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define rep2(i,a,b) for (ll i = (a); i < (b); ++i)

#define INF 1E18



int main(){
    int n;
    cin >> n;

    int a[9] = {111,222,333,444,555,666,777,888,999};

    rep(i,9){
        if(n<=a[i]){
            cout << a[i] <<endl;
            return 0;
        }
    }


    return 0;
}
