#include<cmath>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<functional>
#define INF 1e16
#define N (1000000000+7)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> Q;

ll sum[505][505];

int main(void){
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i<m;i++){
        int p,q;
        cin>>p>>q;
        sum[p][q]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sum[i][j]=sum[i][j]+sum[i][j-1];
        }
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
            sum[i][j]=sum[i][j]+sum[i-1][j];
        }
    }
    for(int i=0;i<q;i++){
        int P,Q;
        cin>>P>>Q;
        cout<<sum[Q][Q]+sum[P-1][P-1]-sum[P-1][Q]-sum[Q][P-1]<<endl;
    }
    return 0;
}