#include<bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

#pragma GCC optimize("Ofast")



using namespace std;

bool is_integer( float x ){
    return floor(x) == x;
}
bool is_integer(double x){
    return floor(x) == x;
}


int main() {

    double n,k; cin >> n >> k;
    double ans = 0;
    double d = n;

    for(int i = 1; i <= n; i ++){
        if(i >= k) ans += 1/d;
        else{
            double tmpD = 1;
            double tmpI = i;

            while(tmpI < k){
                tmpI *= 2;
                tmpD *= 2;
            }

            ans += 1/(tmpD*d);
        }
    }

    cout << fixed << setprecision(13) << ans;


    return 0;
}









