#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <iomanip>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, 1, 0, -1};

int main(void){
    ll n;
    cin >> n;
    vector<ll> s;
    s.push_back(2);
    for(ll i = 3; i <= 55555; i++){
        bool ok = true;
        for(ll j = 2; j <= sqrt(i); j++){
            if(i%j==0){
                ok = false;
                break;
            }
        }
        if(ok==true && i%5==1){
            s.push_back(i);
        }
    }
    for(ll i = 0; i < n; i++)
        cout << s[i] << " ";
    cout << endl;
    return 0;
}
