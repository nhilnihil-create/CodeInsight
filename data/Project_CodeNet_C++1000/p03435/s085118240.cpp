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
    vector<vector<int>>c(3,vector<int>(3));
    bool flg=false;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin>>c[i][j];
        }
    }
    for (int a1 = 0; a1 <=100; ++a1) {
        for (int a2 = 0; a2 <=100; ++a2) {
            for (int a3 = 0; a3 <=100; ++a3) {
                vector<int>b(3);
                b[0]=c[0][0]-a1;
                b[1]=c[0][1]-a1;
                b[2]=c[0][2]-a1;
                bool ch=true;
                vector<int>a(3);
                a[0]=a1;
                a[1]=a2;
                a[2]=a3;
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        if(c[i][j]!=a[i]+b[j])ch=false;
                    }
                }
                if(ch)flg=true;
            }
        }
    }
    if(flg)puts("Yes");
    else puts("No");
    return 0;
}