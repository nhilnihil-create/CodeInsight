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
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;
ll ans=INF;
ll N,A,B,C;
vector<int> l(10);

void dfs(int a, int b, int c, int i, ll now){
    if(i==N){
        if(a==0 || b==0 || c==0){
            return;
        }else{
            ans=min(ans,now+abs(A-a)+abs(B-b)+abs(C-c));
            return;
        }
    }
    //cout<<now<<" ";
    for(int j=0;j<4;j++){
        if(j==0){
            if(a!=0){
                dfs(a+l[i],b,c,i+1,now+10);
            }else{
                dfs(a+l[i],b,c,i+1,now);
            }
        }else if(j==1){
            if(b!=0){
                dfs(a,b+l[i],c,i+1,now+10);
            }else{
                dfs(a,b+l[i],c,i+1,now);
            }
        }else if(j==2){
            if(c!=0){
                dfs(a,b,c+l[i],i+1,now+10);
            }else{
                dfs(a,b,c+l[i],i+1,now);
            }
        }else{
            dfs(a,b,c,i+1,now);
        }
    }
}

int main(){
    cin>>N>>A>>B>>C;
    for(int i=0;i<N;i++) cin>>l[i];
    dfs(0,0,0,0,0);
    cout<<ans<<endl;
    return 0;
}