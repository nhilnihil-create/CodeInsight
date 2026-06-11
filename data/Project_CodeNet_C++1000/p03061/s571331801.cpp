#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    while(b != 0){
        ll tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}


int main(){
    int n;
    cin >> n;
    vector<int> array(n);
    for(int i=0;i<n;i++) cin >> array.at(i);
    ll allg,maxg,g1,g2;
    if( n == 2 ){
        cout << max(array.at(0),array.at(1)) << endl;
        return 0;
    }
    for(int i=1;i<n;i++){
        if(i == 1){
            allg = array.at(0);
            maxg = array.at(1);
            continue;
        }
        g2 = gcd(allg,array.at(i));
        allg = gcd(allg,array.at(i-1));
        g1 = gcd(maxg,array.at(i));
        maxg = max(max(g1,g2),allg);
    }
    cout << maxg << endl;
}