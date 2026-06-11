#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N;
	int A;
	cin>>N;
	cin>>A;
	N%=500;
	if(N<=A) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
