#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll =  long long ;
using P = pair<int,int> ;
const int INF = 1e9;
const int MOD = 1000000007;

int main(){
    ll n,m,d;
    cin >> n >> m >> d;
    if(d >= n){
        printf("%.10f",0.0);
        return 0;
    }if(d==0){
        printf("%.10f",((m-1)*(n-d))/(double)(n*n));
        return 0;
    }
    printf("%.10f",(2*(m-1)*(n-d))/(double)(n*n));
    return 0;
}