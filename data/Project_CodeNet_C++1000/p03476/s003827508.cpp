#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool is_PrimeNumber(int x){
    bool Prime=true;
    rep(i,(int)sqrt(x)){
        if((i+2)!=x&&x%(i+2)==0)Prime=false;
    }
    return Prime;
}


int main(){
    int Q;
    cin>>Q;
    int ans[100001];
    ans[0]=0;
    ans[1]=0;
    ans[2]=0;
    rep(i,99998){
        if(is_PrimeNumber(i+3)&&is_PrimeNumber((i+4)/2))ans[i+3]=ans[i+2]+1;
        else ans[i+3]=ans[i+2];
    }
    rep(i,Q){
        int l,r;
        cin>>l>>r;
        cout<<ans[r]-ans[l-1]<<endl;
    }
    return 0;
}