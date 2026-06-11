#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    int N;cin>>N;
    vector<int>L(N);
    rep(i,N){
        cin>>L.at(i);
    }
    int sum=0;
    sort(all(L));
    rep(i,N-1){
        sum+=L.at(i);
    }
    if(L.at(N-1)<sum){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}