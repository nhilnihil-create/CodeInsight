#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
typedef pair<int,int> pa;
typedef vector<int> vec;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
int n,a[500010],top,stk[500010],v[500010];
bool ck(int o){
	int now=a[1];
	top=0;
	FOR(i,2,n){
		if (a[i]>now){now=a[i];continue;}
		while (top && stk[top]>a[i]) --top;
		if (stk[top]!=a[i]) stk[++top]=a[i],v[top]=0;
		++v[top];
		if (v[top]>o-1){
			int t=top;
			while (t && stk[t-1]==stk[t]-1 && v[t]>=o-1) --t;
			if (t<1) return 0;
			if (v[t]>=o-1){
				stk[t]--;
				v[t]=1;
				top=t;
				if (o<2) return 0;
			}
			else{
				++v[t];
				top=t;
			}
		}
		now=a[i];
	}
	return 1;
}
int main(){
	cin>>n;
	FOR(i,1,n) getint(a[i]);
	int l=1,r=n;
	while (l<r){
		int o=l+r>>1;
		if (ck(o)) r=o;
		else l=o+1;
	}
	cout<<r<<endl;
	return 0;
}