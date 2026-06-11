#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue> //priority_queue
#include <map>
#include <set> //multiset set<int,greater<int>>大到小
#include <vector>// vector<int>().swap(v);清空释放内存
#include <stack>
#include <cmath> // auto &Name : STLName  Name.
#include <utility>
#include <sstream>
#include <string>//__builtin_popcount(ans);//获取某个数二进制位1的个数
#define mod 1000000007
#define mod9 998244353
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
typedef long double ld;
const db eps=1e-10;
const int INF = 0x3f3f3f3f;
const ll inf=0x3f3f3f3f3f3f3f3f;
#define rep(i,be,en) for (int i=be;i<=en;i++)
#define per(i,be,en) for (int i=en;i>=be;i--)
//ll ksm(ll a,ll b,ll c){ll ans=1;a=a%c;while(b>0){if(b%2) ans=(ans*a)%c;b=b/2;a=(a*a)%c;}return ans;}
using namespace std;

const int N=2e5+7;
int t,n,m,fl=0;
int prime[N]={0};//记录素数
int vis[N]={0};//记录除本身最大因子
int cnt=0;//素数个数
void Euler_prime(int x){
    for(int i=2;i<=x;++i){
        if(vis[i]==0){
            prime[cnt++]=i;
            vis[i]=1;
        }
        for(int j=0;j<cnt;++j){
            if(i*prime[j]>x)//判断是否越界
                break;
            vis[i*prime[j]]=i;//筛数
            if(i%prime[j]==0)//时间复杂度为O(n)的关键！
                break;
        }
    }
}
int main(){
    Euler_prime(55556);
    scanf("%d",&n);
    rep(i,0,cnt-1){
        if(prime[i]%10==1){
            printf("%d%c",prime[i],n==1?'\n':' ');
            n--;
        }
        if(n<=0) break;
    }
    return 0;
}