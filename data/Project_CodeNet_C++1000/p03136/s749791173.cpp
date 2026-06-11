#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using ll=long long;
using namespace std;
const long MOD=1e9+7;
template<class T>
T lcm(T a,T b){
    return a/__gcd(a,b)*b;
}

int main(){
    long n;cin >> n;
    long sum,m;
    sum=0;m=-1;
    for(int i=0;i<n;i++){
        long z;
        cin >> z;
        sum+=z;
        if(z>=m){
            m=z;
        }
    }

    cout << (sum-m>m?"Yes":"No");

    return 0;
}