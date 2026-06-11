#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef pair<int,int> ii;
const int maxn=(1<<18)+5;
ii res[maxn];
int a[maxn];
void merge(int x,int y) {
	if(res[y].se>=res[x].fi) {
		res[x].fi=res[y].fi;
		res[x].se=res[y].se;
	}
	else if(res[y].se<=res[x].fi&&res[y].fi>=res[x].fi) {
		res[x].se=res[x].fi;
		res[x].fi=res[y].fi;
	}
	else if(res[y].fi<=res[x].fi&&res[y].fi>=res[x].se) {
		res[x].se=res[y].fi;
	}
}
signed main() {
    int n;
    cin>>n;
    for(int i=0 ; i<(1<<n) ; i++) {
        cin>>a[i];
        res[i].fi=a[i];
        res[i].se=-1;
    }
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<(1<<n) ; j++) {
            if((j&(1<<i))==0) {
                // no bit i
                merge(j|(1<<i),j);
            }
        }
    }
    int ans=0;
    for(int i=1 ; i<(1<<n) ; i++) {
        ans=max(ans,res[i].fi+res[i].se);
        cout<<ans<<'\n';
    }
}