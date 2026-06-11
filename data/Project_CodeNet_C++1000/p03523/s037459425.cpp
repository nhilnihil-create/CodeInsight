#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1000000];
int main()
{
	string ans[]={"AKIHABARA",\
								"AKIHABAR",\
								"AKIHABRA",\
								"AKIHBARA",\
								"AKIHBAR",\
								"AKIHBRA",\
								"AKIHBR",\
								"KIHABARA",\
								"KIHABAR",\
								"KIHABRA",\
								"KIHABR",\
								"KIHBARA",\
								"KIHBAR",\
								"KIHBRA",\
								"KIHBR",\
								};
	string s;
	cin>>s;
	for(ll i=0;i<15;i++)if(ans[i]==s){cout<<"YES"<<endl;return 0;}
	cout<<"NO"<<endl;
	return 0;
}
