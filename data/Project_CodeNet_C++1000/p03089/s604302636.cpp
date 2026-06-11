#define _LIBCPP_DEBUG 0
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef vector<int> vi;
typedef long long ll;



int main(){
    ll N;cin>>N;
    ll a[110];
    vector<ll> b(110);
    rep(i,0,N){
        cin>>b.at(i);
        if(i+1<b.at(i)){
            cout<<-1<<endl;
            return 0;
        }
    }
    rep(n,0,N){
        for(int i=N-1-n;i>=0;i--){
            if(b.at(i)==i+1){
                a[N-1-n]=b.at(i);
                b.erase(b.begin()+i);
                break;
            }
        }
    }
    rep(i,0,N){
        cout<<a[i]<<endl;
    }
    
}




