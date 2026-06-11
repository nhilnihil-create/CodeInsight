#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
#define INF 1e18
#define ret return

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector < pair<int, int> > vii;
typedef long double ld;
typedef tree<pair<int,int>, null_type, less<pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

vector<int> minx[222222];
int x, y, h, w, n;
set <ii> block;

int f(int x, int pos){
	int ans = h+1;
	int lo=0;
	int hi=minx[pos].size();
	int mid;
	while(lo<=hi){
		mid=lo+(hi-lo)/2;
		if(minx[pos][mid]>x){
			ans=min(ans,minx[pos][mid]);
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
	}
	return ans;
}

int main(){
	cin >> h >> w >> n;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		block.insert(mp(x,y));
		minx[y].pb(x);
	}
	for(int i = 1; i <= h; i++){
		block.insert(mp(i,w+1));
	}
	for(int i = 1; i <= w; i++){
		block.insert(mp(h+1,i));
		minx[i].pb(h+1);
	}
	for(int i = 1; i <= w; i++){
		sort(minx[i].begin(),minx[i].end());
	}
	x=1;y=1;
	int t=1;
	int ans = h+w+1;
	int cnt = 0;
	while(x<=h && y<=w){
		//cout << "*" << x << " " << y << " " << ans << endl;
		if(t>0){
			if(block.count(mp(x+1,y))){
				x=h+1;
				y=w+1;
			}
			else{
				x++;
				cnt++;
			}
		}
		else{
			ans=min(ans,cnt+f(x,y)-x-1);
			if(block.count(mp(x,y+1))==0){
				y++;
				
			}
			ans=min(ans,cnt+f(x,y)-x-1);
		}
		t*=-1;
	}
	
	//cout << "*" << x << " " << y << " " << ans << endl;
	cout << min(cnt,ans)+1;
	
}
