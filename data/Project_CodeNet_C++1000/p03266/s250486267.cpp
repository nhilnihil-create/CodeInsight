#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <iomanip>
#define ll long long

using namespace std;

int main(void){
    ll n, k;
    cin >> n >> k;
    if(k%2!=0){
        ll count = 0;
        for(ll i = 1; i <= n; i++)
            if(i%k==0) count++;
        cout << count*count*count << endl;
    }
    else if(k%2==0){
        ll ca = 0, cb = 0;
        for(ll i = 1; i <= n; i++){
            if(i%k==0)
                ca++;
            if(i%k==(k/2))
                cb++;
        }
        cout << ca*ca*ca+cb*cb*cb << endl;
    }
    return 0;
}
