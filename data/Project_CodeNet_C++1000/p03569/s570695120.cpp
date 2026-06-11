#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	deque<char> dq;
	int ret=0;
	string s; cin>>s;
	for (char ch : s)
		dq.push_back(ch);
	while(!dq.empty()) {
		if(dq.size()==1) break;
		if(dq.front()==dq.back()) dq.pop_front(), dq.pop_back();
		else {
			if(dq.front()=='x') dq.pop_front(), ret++;
			else if(dq.back()=='x') dq.pop_back(), ret++;
			else {
				cout<<-1<<"\n";
				return 0;
			}
		}
	}
	cout<<ret<<"\n";
	return 0;
}