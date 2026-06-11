#pragma GCC optimize(2)
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue> //priority_queue<int, vector<int>, greater<int> > q;从小到大
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
const db eps=1e-7;
#define PII pair<int,int>
//const db pi=acos(-1);
const int INF = 0x3f3f3f3f;
const ll inf=0x3f3f3f3f3f3f3f3f;
#define rep(i,be,en) for (int i=be;i<=en;i++)
#define per(i,be,en) for (int i=en;i>=be;i--)
using namespace std;
const int N=1e4+3;

int T,n,m,k=0,fl=0;

int main(){
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d",&m);
        k+=m;
        fl=max(fl,m);
    }
    if(k-fl>fl) puts("Yes");
    else puts("No");
    return 0 ;
}