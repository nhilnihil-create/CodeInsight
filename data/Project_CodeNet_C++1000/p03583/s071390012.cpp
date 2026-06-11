#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using ld=long double;

int main(){
   ll n;cin >>n;
   ll a,b,c;
    for (int h = 1; h <=3500; ++h) {
        for (int w =1; w <=3500; ++w) {
            ll t=4*h*w-(w+h)*n;
            if(t<=0)continue;
            if(n*h*w%t==0){
                a=h,b=w,c=n*h*w/t;
                break;
            }
        }
    }
    cout <<a<<" "<<b<<" "<<c<<endl;
}
