#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

#define INF (1ll<<60)


long long M = 1000000007;

long long gcd(long long x, long long y){
    if(y==0)return x;
    return gcd(y,x%y);
}

bool solve(long long a, long long b, long long c, long long d){
    if(b>d)return false;
    if(a<b)return false;
    //suppose a>=b, b<=d
    if(c>=b-1)return true;
    //suppose c<b-1;
    long long k = a%b;
    long long l = gcd(b,d);
    if (l * (b/l - 1) + k % l > c)return false;
    return true;
}


int main(int argc, char const *argv[]) {
    int t;cin>>t;
    for(int tt=0;tt<t;tt++){
        long long a,b,c,d;cin>>a>>b>>c>>d;
        if(solve(a,b,c,d))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}