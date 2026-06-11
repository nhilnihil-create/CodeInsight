#include <iostream>
#include <cstring>
#include <cstdio>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
typedef pair<double,double>P_D;
#define rep(i, n) for (int i = 0; i < n; i++)
#define reprev(i, n) for (int i = n - 1; i >= 0; i--)
#define MAX 100100
#define MAX_N 200100
#define SENTINEL 2000000000
const int MOD = 1e9+7;
#define NIL -1
const int INF = 1 << 29;
#define ALL(a)  (a).begin(),(a).end()
int n,k;

int main(){
    cin>>n>>k;
    vector<ll>num(k,0);
    for(int i=1;i<=n;i++)num[i%k]++;
    ll res=0;
    rep(a,k){
        int b=(k-a)%k;
        int c=(k-a)%k;
        if((b+c)%k!=0)continue;
        res+=num[a]*num[b]*num[c];
    }
    cout<<res<<endl;
}