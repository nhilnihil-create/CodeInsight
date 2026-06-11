#include<bits/stdc++.h>
using namespace std;    
int a[100005];
int main()
{
   int n,ans=0;
   int x;
   cin >> n;
   for (int i=1;i<=n;i++){
   	cin >> x;
   	if (x>n) ans++;
   	else a[x]++;
}
    for (int i=1;i<=100005;i++){
    	if (a[i]==0) continue;
    	if (a[i]<i) ans+=a[i];
    	if (a[i]>i) ans+=a[i]-i;
    }
    cout << ans;
    return 0;
}