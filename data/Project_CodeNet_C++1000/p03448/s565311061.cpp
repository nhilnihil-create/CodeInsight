#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF = numeric_limits<long long>::max();
#define intf int_fast64_t


int main(){
    vector<intf> a(3);
    for(auto &e:a) cin >>e;
    vector<intf> list = {500,100,50};
    intf ct=0,x;
    cin >>x;

    rep(h,a[0]+1){
        rep(i,a[1]+1){
            rep(j,a[2]+1){
                if(x==(h*500+i*100+j*50)){
                    ct++;
                }
            }
        }

    }

    cout << ct <<endl;

}