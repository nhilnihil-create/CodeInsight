#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;
 
vector<ll>g[10010];
bool visited[10010];
int A(int x){
    if(x>=0)return x;
    else return -x;
}
int main(void){
    int n,Z,W;
    cin>>n>>Z>>W;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    if(n==1){
        cout<<A(W-a[n-1])<<endl;
        return 0;
    }
    cout<<max(A(W-a[n-1]),A(a[n-1]-a[n-2]))<<endl;
    return 0;
}