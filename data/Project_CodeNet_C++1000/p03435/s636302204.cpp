#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    ll c[3][3];
    ll sum=0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >>c[i][j];
            sum+=c[i][j];
        }
    }
    if(sum%3!=0){
        puts("No");
        return 0;
    }
    sum/=3;
    vector<ll>a(3);
    vector<ll>b(3);
    a[1]=c[1][0]+c[1][1]+c[0][1]+c[2][1]+c[1][2]-sum;
    b[0]=c[1][0]-a[1];
    b[1]=c[1][1]-a[1];
    b[2]=c[1][2]-a[1];
    a[0]=c[0][1]-b[1];
    a[2]=c[2][1]-b[1];
    bool flg=true;
    if(c[0][0]!=a[0]+b[0])flg=false;
    if(c[0][2]!=a[0]+b[2])flg=false;
    if(c[2][0]!=a[2]+b[0])flg=false;
    if(c[2][2]!=a[2]+b[2])flg=false;
    if(flg)puts("Yes");
    else puts("No");
    return 0;
}