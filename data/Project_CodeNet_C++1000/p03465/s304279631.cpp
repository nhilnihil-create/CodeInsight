#include<bits/stdc++.h>
using namespace std;
const int maxn=2010;
bitset<2000010> f;
int a[maxn];
int n,sum;
int main(){
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i],sum+=a[i];
	f[0]=1;
	for(int i=n;i>=1;--i)
		f|=f<<a[i];
	for(int i=(sum+1)>>1;i<=sum;++i)
		if(f[i]){
			cout << i << endl;
			return 0;
        }
    return 0;
}