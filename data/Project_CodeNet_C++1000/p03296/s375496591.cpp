#include <bits/stdc++.h>

using namespace std;
const int maxn=105;
int n;
int a[maxn];
int vis[maxn],cnt;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),vis[a[i]]=1;
	for (int i=1;i<=n;i++){
		if (a[i]==a[i-1]){
			for (int j=1;j<=n;j++){
				if (!vis[j]){
					vis[j]=1;
					cnt++;
					a[i]=j;
					break;
				}
			}
		}
	}
	cout << cnt << '\n';
} 