#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

//read_kaisetsu
int main() {
    int n,m;cin>>n>>m;
    pair<int,int>a[m];
    rep(i,m)cin>>a[i].second>>a[i].first;
    sort(a,a+m);

    int ans=1;
    int tmp=a[0].first-1;
    rep(i,m-1){
        if(a[i+1].second<=tmp)continue;
        else {
            tmp=a[i+1].first-1;
            ++ans;
        }
    }
    cout<<ans<<endl;
	return 0;
}