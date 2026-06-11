#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=110;
char a[N],b[N],c[N];
int main() {
    int n,ans=0;
    scanf("%d%s%s%s",&n,a,b,c);
    for(int i=0;i<n;i++) {
	if(a[i]==b[i]) {
	    if(b[i]!=c[i]) ++ans;
	}
	else if(a[i]==c[i]||b[i]==c[i]) ++ans;
	else ans+=2;
    }
    cout<<ans;
    return 0;
}