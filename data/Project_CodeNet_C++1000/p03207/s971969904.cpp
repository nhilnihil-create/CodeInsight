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
const ll INF=10000000000;
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
int d;
int a[DMAX];
int main(){
	cin>>d;
	int ans=0;
	for(int i=1;i<=d;i++){
		cin>>a[i];
		ans+=a[i];
	}
	sort(a+1,a+d+1);
	ans-=(a[d]/2);
	cout<<ans<<endl;
	return 0;
}