#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[1011000];
int b[1010100];
int sum[1010100];

struct Tr{
    int tr[400010];
    void clear(){for (int i=1;i<=400010;i++) tr[i] = 0;}
    void add(int x,int v){
	    for (int i=x;i<=400010;i+=(i&(-i))) tr[i] += v;
	}
	int ask(int x){
	    int Ans=0;
	    for (int i=x;i>=1;i-=(i&(-i))) Ans += tr[i];
	    return Ans;
	}
};

Tr tr; 
bool check(int x){
    for (int i=1;i<=n;i++)
      if (a[i]>=x) b[i]=1;else b[i]=-1;
//    if (x == 29) {cout<<"OK:"<<' ';for (int i=1;i<=n;i++) cout<<b[i]<<' ';cout<<endl;}
    for (int i=0;i<=n+1;i++) sum[i] = 0;
    for (int i=1;i<=n;i++) sum[i] = sum[i-1]+b[i];
//    for (int i=1;i<=n;i++) cout<<sum[i]<<' ';
//    cout<<endl;
    int ans=0;
	for (int i=1;i<=n;i++){
	    ans += tr.ask(sum[i]+1+n);
	    tr.add(sum[i]+1+n,1);
	    ans += sum[i] >= 0;
	}
	tr.clear();
//	cout<<ans<<endl;
	return ans>=(n*(n+1)/2+1)/2;
}

signed main(){
    scanf("%lld",&n);
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
    int l = 0,r = 2e9+100;
    while (l+1<r){
	    int mid = l+r>>1;
	    if (check(mid)) l = mid;else r = mid;
//	    cout<<l<<' '<<r<<endl;
	}
	printf("%lld",check(l)?l:r);
	return 0;
}