#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define bg begin()
#define ed end()
#define pii pair<int,int>

int main()
{
	int n,k;
	int cnt[4]={};
		f(3){
			int add1,add2;
			cin >> add1 >> add2;
			cnt[add1]++,cnt[add2]++;
		}
		int s=0;
		f1(4){
			s+=(cnt[i]&1);
		}
		if(s==0||s==2){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	
}
