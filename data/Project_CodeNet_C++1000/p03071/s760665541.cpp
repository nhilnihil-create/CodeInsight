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
   int a,b;
   cin>>a>>b;
   int ans=0;
    for (int i = 0; i < 2; ++i) {
        if(a>=b){
            ans+=a;a--;
        }
        else {
            ans+=b;b--;
        }
    }
    cout <<ans <<endl;
}
