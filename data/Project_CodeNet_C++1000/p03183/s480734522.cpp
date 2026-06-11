# include <bits/stdc++.h>
using namespace std;
# define MOD 1000000007
typedef long long ll;
class box{
public:
    int w, s, v;
};
bool compare(box a, box b){
    return a.s + a.w < b.s + b.w;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n;
	cin>>n;
	box boxes[n];
	for(int i=0;i<n;i++){
	    cin>>boxes[i].w>>boxes[i].s>>boxes[i].v;
	}
	sort(boxes, boxes + n, compare);
// 	for(int i=0;i<n;i++){
// 	    cout<<boxes[i].w<<" "<<boxes[i].s<<" "<<boxes[i].v<<"\n";
// 	}
    int MAXS = 30001;
	vector<ll> dp(MAXS);
	for(int i=0;i<n;i++){
	    for(int w=min(boxes[i].s, MAXS - boxes[i].w);w>=0;w--){
	        dp[w + boxes[i].w] = max(dp[w + boxes[i].w], dp[w] + boxes[i].v);
	    }
	}
	ll ans = 0;
	for(int i=0;i<MAXS;i++){
	    ans = max(ans, dp[i]);
	}
	cout<<ans;
	return 0;
}