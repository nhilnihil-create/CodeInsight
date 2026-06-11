#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int c[n],a[n],b[n];
    vector<vector<int> > v(n);
    for(int i=0;i<n-1;i++){
    	cin>>a[i]>>b[i];
    	a[i]--,b[i]--;
    	v[a[i]].pb(b[i]);
    	v[b[i]].pb(a[i]);
    }
    bool maki[n];
    memset(maki,0,sizeof(maki));
    int ans[n];
    queue<int> q;
    int index=0;
    for(int i=0;i<n;i++)cin>>c[i];
    sort(c,c+n);
    reverse(c,c+n);
    q.push(0);
    while(!q.empty()){
    	int now=q.front();
    	q.pop();
    	ans[now]=c[index];
    	index++;
    	maki[now]=true;
    	for(auto& i:v[now]){
    		if(!maki[i])q.push(i);
    	}
    }
    int sum=0;
    for(int i=0;i<n-1;i++){
    	sum+=min(ans[a[i]],ans[b[i]]);
    }
    cout << sum<<endl;
    for(int i=0;i<n;i++){
    	cout << ans[i] <<" ";
    }
    cout << endl;

    return 0;
}
