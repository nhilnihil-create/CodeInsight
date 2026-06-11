#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(){
    int n; cin >> n;
    vector<int> a(100000);
    int MIN=1000000000;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i]<MIN) MIN = a[i];
    }
    int el = gcd(a[0], a[1]);
    for(int i=0; i<n; i++){
        el = gcd(el, a[i]);
    }
    cout << el << endl;
    return 0;
        
}