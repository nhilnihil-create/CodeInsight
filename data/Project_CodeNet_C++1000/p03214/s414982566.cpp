#include <iostream>
#include <cstring>
#include <cstdio>
#include<cstdint>
#include <utility>
#include <algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<string>
#include<list>
#include<deque>
#include<stack>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
#define reprev(i, n) for (int i = n - 1; i >= 0; i--)
#define MAX 100100
#define MAX_N 200100
#define SENTINEL 2000000000
const int MOD = 1e9+7;
#define NIL -1
const int INF = 1 << 29;
int n,a[101];
int main(){
    cin>>n;
    double sum=0;
    rep(i,n){
        cin>>a[i];
        sum+=a[i];
    }
    double m=sum/(double)n;
    double b[n];
    rep(i,n){
        b[i]=abs(a[i]-m);
    }
    double min=1<<29;
    rep(i,n){
        if(min>b[i])min=b[i];
    }
    int ans;
    rep(i,n){
        if(min==b[i]){
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
return 0;
}