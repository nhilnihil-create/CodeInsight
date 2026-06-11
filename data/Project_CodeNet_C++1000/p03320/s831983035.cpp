#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;

ll fsum(ll x){
    ll a = 0;
    while(x){
        a += (x % 10);
        x /= 10;
    }
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<ll>v;
    for(int i = 1;i < 10;i++){
        v.push_back(i);
    }
    v.push_back(19);
    ll K;
    cin>>K;
    ll last = 19;
    while(v.size() < K){
        //去向量的最后一个fsum 
        ll p = fsum(last);
        ll add = 1;
        //99 :109 119 
        while((last+add)*fsum(last+add*2) > (last+2*add)*fsum(last+add)){
            add *= 10;
        }
        last += add;
        v.push_back(last);
    }
    for(int i = 0;i < K;i++){
        cout<<v[i]<<endl;
    }
    return 0;
}
