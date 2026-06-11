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
    int N,Y;
    cin>>N>>Y;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            int l=N-i-j;
            if(10000*i+5000*j+1000*l==Y && l>=0 && l<=N){
                printf("%d %d %d \n",i,j,l);
                return 0;
            }
        }
    }
    cout<<"-1 -1 -1"<<endl;

}