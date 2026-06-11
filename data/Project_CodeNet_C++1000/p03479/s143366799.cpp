#include <iostream>
#include<string>
#include <cstdio>
#include<utility>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<bitset>
#include<queue>
#include<set>
#include <limits>
#include <numeric>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
typedef pair<double,double>P_D;
#define PI 3.1415926535897932384626433832795
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define reprev(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define ALL(a)  (a).begin(),(a).end()
#define MAX 100100
#define MAX_N 200100
#define SENTINEL 2000000000
#define MAX_B 1001001
#define NIL -1
#define MOD 1000000007
#define INF 1 << 29
#define INFTY 1000000000000000000LL

int main(){
    ll x,y;cin>>x>>y;
    int ans=0;
    while(x<=y){
        x*=2;
        ans++;
    }
    cout<<ans<<endl;
}