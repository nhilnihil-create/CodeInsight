#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <utility>

#define reps(i,s,n) for(long long (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    ll w=0;

    reps(n,1,3510){
        reps(h,1,3510){
            ll t1 = (ll)N*h*n;
            ll t2 = (ll)(4*h*n - N*n - N*h);
            if(t2 > 0 ){
                if(t1 % t2 == 0){
                    w = t1 / t2;
                    cout << h << " " << n << " " << w << endl;
                    return 0;
                }
            }
        }
    }


    return 0;
}