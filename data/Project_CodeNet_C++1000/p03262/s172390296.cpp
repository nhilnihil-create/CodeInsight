#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a > b){
        a = a - b;
    }
    else if(a == b){
        return a;
    }
    else{
        b = b - a;
    }
    return  gcd(a,b);
}

int main() {
    long long n,x;
    cin >> n >> x;
    vector<long long> v(n);
    for(int i=0; i<n; i++){
        cin >> v.at(i);
        v.at(i) = abs(x-v.at(i));
    }
    if(n == 1){
        cout << v.at(0) << endl;
        return 0;
    }
    else if(n == 2){
        cout << gcd(v.at(0),v.at(1)) << endl;
        return 0;
    }
    else{
        int gc = gcd(v.at(0),v.at(1));
        for(int i=2; i<n; i++){
            gc = gcd(gc,v.at(i));
        }
        cout << gc << endl;
        return 0;
    }
    
}
