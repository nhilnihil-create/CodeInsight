#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){

    ll X,Y; cin >> X >> Y;
    vector<ll> vec{};
    
    ll index = X;
    while(1){
        vec.push_back(index);
        index *= 2;
        if(index > Y) break;
    }
    
    cout << vec.size() << endl;
}