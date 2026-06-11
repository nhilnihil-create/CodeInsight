#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#define mp make_pair
#define pb push_back
#define mem(i,a) memset(i,a,sizeof(i))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
const int INF=1000000007;
const int DMAX=100000+5;
const int MOD=6000000;
template<class T> inline void read(T &x){
    x=0; 
    T f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-'){
            f=-1;
        }
        ch=getchar();
    }
    while(ch<='9' && ch>='0'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    x*=f;
}
int k;
int n;
int a[DMAX];
int main(){
	read(n);
	read(k);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=INF;
	for(int i=k;i<=n;i++){
		ans=min(ans,a[i]-a[i-k+1]);
	}
	printf("%d\n",ans );
	return 0;
}