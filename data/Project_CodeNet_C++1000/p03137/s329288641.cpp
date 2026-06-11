#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=9999999999;
int a[510][510];


int main(){
    int n,m;
    cin>>n>>m;
    vector<int> x(m);
    for(int i=0;i<m;i++) cin>>x[i];
    sort(x.begin(), x.end());
    vector<int> dis(m-1);
    for(int i=0;i<m-1;i++) dis[i]=x[i+1]-x[i];
    sort(dis.begin(), dis.end(), greater<int>());
    int ans=*x.rbegin()-*x.begin();
    for(int i=0;i<min(n-1,m-1);i++){
        ans-=dis[i];
    }
    cout<<max(0,ans)<<endl;

}