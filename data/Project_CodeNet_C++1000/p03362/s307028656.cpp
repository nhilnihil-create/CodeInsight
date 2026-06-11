#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

ll m=55555;
vector<bool>ch(m+100,true);
vector<ll>p;

void f(){
    ch[0]=ch[1]=false;
    for(int i=2;i<m;i++){
        if(ch[i]){
            if(i%5==1)p.push_back(i);
            for (int j = 2*i; j < m; j+=i) {
                ch[j]=false;
            }
        }
    }
}

int main(){
    f();
//    cout <<p.size()<<endl;
    ll n;cin >>n;
    for (int i = 0; i < n; ++i) {
        cout <<p[i]<<" ";
    }
    cout <<endl;
    return 0;
}
