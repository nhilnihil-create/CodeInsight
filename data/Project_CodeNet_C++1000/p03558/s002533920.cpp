/*
  code by RyeCatcher
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <utility>
#include <queue>
#include <vector>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <iostream>
#define DEBUG freopen("dat.in","r",stdin);freopen("wa.out","w",stdout);
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define ri register int
#define ll long long
#define ull unsigned long long
#define SIZE 1<<22
using std::min;
using std::max;
using std::deque;
using std::vector;
using std::pair;
using namespace __gnu_pbds;
inline char gc(){
    static char buf[SIZE],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,SIZE,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
template <class T>inline void read(T &x){
    x=0;int ne=0;char c;
    while((c=gc())>'9'||c<'0')ne=c=='-';x=c-48;
    while((c=gc())>='0'&&c<='9')x=(x<<3)+(x<<1)+c-48;x=ne?-x:x;return ;
}
const int maxn = 10000005;
const int inf=0x7fffffff;
typedef pair<int,int> pii;
bool vis[maxn];
deque<pii>q;
int k;
int main(){
	int x,y;
	read(k);
	q.push_back(pii(1,1));
	while(q.size()){
		x=q.front().first,y=q.front().second;q.pop_front();
		if(vis[x])continue;vis[x]=1;
		if(x==0){
			printf("%d\n",y);
			break;
		}
		q.push_front(pii(x*10%k,y));
		q.push_back(pii((x+1)%k,y+1));
	}
	return 0;
}
