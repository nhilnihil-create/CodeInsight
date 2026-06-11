#include <bits/stdc++.h>
#include <stdio.h>
#include <cmath>
using namespace std;

#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
#define rep1(i,n) for(long long i=1; i<=(long long)(n);i++)
//rep1は「１からnまで」の繰り返し
#define rep-(i,n) for(long long i=n;i>=0;i--)

typedef long long ll;

const ll inf = 1e18+7;
const ll mod = 1e9+7;


int main() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    if((abs(a-c)<=d)||((abs(a-b)<=d)&&(abs(b-c)<=d)))
        cout<<"Yes"<<endl;
    else {
        cout<<"No"<<endl;
    }
}
