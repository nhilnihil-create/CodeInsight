#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    ll max_number = 55555;
    vector<bool> era(max_number+1, true);
    era.at(0) = false;  era.at(1) = false;
    for(i = 2;i <= max_number;++i){
        if(era.at(i)){
            for(j = 2*i;j <= max_number;j += i){
                era.at(j) = false;
            }
        }
    }
    ll num = 0;
    ll now = 1;
    while(num < n){
        if(era.at(now) && (now%5 == 1)){
            cout << now << endl;
            ++num;
        }
        ++now;
    }
    return 0;
}