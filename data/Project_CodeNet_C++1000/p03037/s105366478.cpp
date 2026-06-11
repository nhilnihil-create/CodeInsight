#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> l(m),r(m);
    vector<int> idl(n),idr(n);
    rep(i,m){
        cin>>l[i]>>r[i];
        l[i]--;
        r[i]--;
        idl[l[i]]=1;
        idr[r[i]]=1;
    }
    int ansl=0,ansr=n;
    rep(i,n){
        if(idl[i]==1){
            ansl=max(ansl,i);
        }
        if(idr[i]==1){
            ansr=min(ansr,i);
        }
    }
    int ans=ansr-ansl+1;
    ans=(ans>0)?ans:0;
    cout<<ans<<endl;
}