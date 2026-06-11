#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int N,K; cin>>N>>K;
	string S; cin>>S; S+='@';
	vector<ii> v;
	string s;
	int cur=1;
	for (int i=1; i<=N; i++) {
		if(S[i]==S[i-1]) cur++;
		else {
			v.push_back({i-cur,i-1}); s+=S[i-1];
			cur=1;
		}
	}
	int left=0, right=0, ret=0;
	cur=K;
	while(1) {
		if(s[right]=='0') cur--;
		if(right==v.size()-1) break;
		if(s[right+1]=='0' && cur==0) break;
		right++;
	}
	ret=max(ret,v[right].second-v[left].first+1);

	while(right!=v.size()-1) {
		while(1) {
			if(s[left]=='0') {
				cur++; left++; break;
			}
			left++;
		}
		while(1) {
			if(s[right]=='0') cur--;
			if(right==v.size()-1) break;
			if(s[right+1]=='0' && cur==0) break;
			right++;
		}
		ret=max(ret,v[right].second-v[left].first+1);
	}
	cout<<ret<<"\n";
	return 0;
}