#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using ll=long long;
using namespace std;

template<class T>
T lcm(T a,T b){
    return a/__gcd(a,b)*b;
}

int main(){
    int a,b,c;cin >> a >> b >> c;
    cout << min(b/a,c);
    return 0;
}