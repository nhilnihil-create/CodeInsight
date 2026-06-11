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
    int N,K;cin>>N>>K;
    int a[N];
    int min=100000;
    int minK;
    int count=0;
    bool f=true;
    int sum=0;
    rep(i,N){
        cin>>a[i];
        /*
        if(a[i]<min){
            min=a[i];
            minK=i;
        }
        */
    }
    while(1){
        if(f){
            sum+=K;
            count++;
            f=false;
        }else{
            sum+=(K-1);
            count++;
        }
        if(sum>=N){
            break;
        }
    }
    cout<<count<<endl;

}