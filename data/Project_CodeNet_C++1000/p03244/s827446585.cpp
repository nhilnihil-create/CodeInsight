#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;

int main(){
    fast_io

    int n;
    cin>>n;

    map<int, int> mpe, mpo;
    rep(i,n){
        int x; cin>>x;
        if(i%2==0){
            mpe[x]++;
        }else{
            mpo[x]++;
        }
    }

    int maxe=0;
    int key=0;
    for(auto m:mpe){
        if(m.second > maxe){
            maxe = m.second;
            key = m.first;
        }
    }
    int maxo = 0;
    for(auto m:mpo){
        if(m.second>maxo && m.first != key){
            maxo=m.second;
        }
    }
    int ans=n-maxo-maxe;

    maxe=0, key=0;
    for(auto m:mpo){
        if(m.second>maxo){
            maxo=m.second;
            key=m.first;
        }
    }
    maxe=0;
    for(auto m:mpe){
        if(m.second>maxe && m.first != key){
            maxe = m.second;
        }
    }
    int ans2=n-maxe-maxo;
    cout<<min(ans, ans2)<<endl;
    return 0;

}
