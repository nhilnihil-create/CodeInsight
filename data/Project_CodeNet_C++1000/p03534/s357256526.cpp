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
#define INF 1e9

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef vector < pair<int, int> > vii;
typedef long double ld;
typedef tree<pair<int,int>, null_type, less<pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

string s;
ll cnt[3], minn;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		cnt[s[i]-'a']++;
	}
	minn=INF;
	minn=min(cnt[0],minn);
	minn=min(cnt[1],minn);
	minn=min(cnt[2],minn);
	cnt[0]-=minn;
	cnt[1]-=minn;
	cnt[2]-=minn;
	for(int i = 0; i < 3; i++){
		if(cnt[i]==0){
			if(cnt[(i+1)%3]+cnt[(i+2)%3]<=1 || (cnt[(i+1)%3]+cnt[(i+2)%3]==2 && cnt[(i+1)%3]==cnt[(i+2)%3])){
				cout<<"YES\n";
				return 0;
			}
			else{
				cout<<"NO\n";
				return 0;
			}
		}
	}
	return 0;
}
