#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	set<string> st={"AKIHABARA", "KIHABARA", "AKIHBARA", "KIHBARA", "AKIHABRA", "KIHABRA", "AKIHBRA", "KIHBRA", "AKIHABAR", "KIHABAR", "AKIHBAR", "KIHBAR", "AKIHABR", "KIHABR", "AKIHBR", "KIHBR"};
	string s; cin>>s;
	cout<<(st.count(s)?"YES":"NO")<<"\n";
	return 0;
}