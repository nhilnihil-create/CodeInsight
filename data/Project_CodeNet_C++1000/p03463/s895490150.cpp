#include <bits/stdc++.h>
#include <stdio.h>
#include <cmath>
using namespace std;

#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
#define rep2(i,s,n) for(long long i=(s); i<(long long)(n);i++)

typedef long long ll;

const ll inf = 1e18+7;
const ll mod = 1e9+7;


int main() {
    int n,a,b;
    cin>>n>>a>>b;

    if((b-a)%2)cout<<"Borys"<<endl;

    else cout<<"Alice"<<endl;
}
