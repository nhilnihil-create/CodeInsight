/*input
4
*/
#include<bits/stdc++.h>
using namespace std;
const int N=21;
const int mod=1e9 + 7;
#define int long long
#define pii pair<int, int>
#define f first
#define s second 
#define mp make_pair
int m, n;vector< pii > adjlist[N];
int b, l;vector<int> bits;
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>l;m=0;
	for(int i=0;(1<<i)<=l;i++) b=i;
	for(int i=0;i<b;i++)
	{
		adjlist[i+1].push_back(mp(i+2,1<<i));adjlist[i+1].push_back(mp(i+2, 0));
		n=i+2;m+=2;
	}
//	l--;
	for(int i=0;(1<<i)<=l;i++)
		if((l&(1<<i))) bits.push_back(i);
	
	//if(bits[0]!=0) bits.insert(bits.begin(), 0);
//	if(((l+1)&l)==0) bits.clear();
	int cur=1<<bits.back();b=bits.size()-2;
	while(b>=0) 
	{adjlist[bits[b]+1].push_back(mp(n, cur));
		m++;
		cur+=1<<bits[b];b--;
	}
	cout<<n<<" "<<m<<endl;
	for(int i=1;i<=n;i++)
	{
		for(auto j:adjlist[i])
		{
			cout<<i<<" "<<j.f<<" "<<j.s<<endl;
		}
	}
}