#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
		tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
		tree_order_statistics_node_update> indexed_multiset;


int n ;
long long ans;
vector<int>b,a,ab;
bool vis[10004];
int main(){	
	cin>>n;
	for(int i = 0; i < n ; i++){
		string s ;cin>>s;
		for(int j = 1 ; j<(int)s.size() ;j++){
			if(s[j]=='B'&& s[j-1]=='A'){
				ans++;
			}
		}
		if(s[0]=='B' &&s[(int)s.size() - 1]=='A')
			ab.push_back(i);
		else if(s[0]=='B')b.push_back(i);
		else if(s[(int)s.size() - 1] == 'A')a.push_back(i);
	}
	int aa = a.size() , bb = b.size() , aabb = ab.size();
	if(aa){
		aa--;
		while(aabb){
			aabb--;
			ans++;
		}
		// last = a
		if(bb){
			bb--;
			ans++;
		}
		//last = b;
		while(aa&&bb){
			aa--;bb--;
			ans++;
		}
	}else{
		if(aabb){
			ans+=(aabb-1);
			if(bb)ans++;
		}
	}
	cout<<ans;
    return 0;
}
