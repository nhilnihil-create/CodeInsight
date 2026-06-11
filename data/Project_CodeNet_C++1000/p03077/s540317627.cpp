#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    vector<ll> power(5);
    ll minpower_station = -1;
    ll minpower = 10000000000000000;
    for(int i=0;i<5;i++){
        cin >> power.at(i);
        if(minpower > power.at(i)){
            minpower = power.at(i);
            minpower_station = i;
        }
    }

    ll time = minpower_station;
    ll time_until_zero;
    if(n % minpower != 0)time_until_zero = n / minpower;
    else time_until_zero = n / minpower  -1;
    time = time + time_until_zero + (5 - minpower_station);
    cout << time << endl;   

}