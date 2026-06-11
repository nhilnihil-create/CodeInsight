#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <map>
#define DEBUG
#undef DEBUG
using namespace std;
typedef long long ll;

ll N;
ll midn;
ll a[100005];

ll func(ll x){
    ll b[100005]; //x以下なら1、そうでなければ0という数列の累積和
    ll BIT[(1<<18)+1]; //累積和のBinary Index Tree
    for(ll i=0;i<=(1<<18);i++){
        BIT[i]=0;
    }
    b[0]=1e5+1;
    for(int i=1;i<=N;i++){
        b[i]=b[i-1];
        if(a[i-1]<=x){b[i]++;}
        else{b[i]--;}
    }
#ifdef DEBUG
#endif
    
    //
    ll ans=0;
    int j = b[0];
    while(j<=(1<<18)){
        BIT[j]++;
        j=j+((-j)&j);
    }
    for(int i=1;i<=N;i++){
        int j = b[i]-1;
        while(j>0){
            ans += BIT[j];
            j=j-((-j)&j);
        }
        j = b[i];
        while(j<=(1<<18)){
            BIT[j]++;
            j=j+((-j)&j);
        }
    }
    return ans;
}

int main(){
    cin>>N;
    midn = N*(N+1)/4+1;
    for(int i=0;i<N;i++){
        cin>>a[i];
    }
    ll left=0,right=1e9,mid;
    while(right-left>1){
        mid=(left+right)/2;
#ifdef DEBUG
        cout<<mid<<endl;
#endif
        if(func(mid)<midn){
            left=mid;
        }else{
            right=mid;
        }
    }
    cout<<right<<endl;
    return 0;
}
