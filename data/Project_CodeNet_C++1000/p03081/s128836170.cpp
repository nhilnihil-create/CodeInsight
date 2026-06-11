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

int main(){
	int n , m;
	while(cin >> n >> m){
		string s;
		//cin >> n >> m;
		cin >> s;
		int cont[n+5] = {};
		int op[m+5][2] = {};
		for(int i=1;i<=n;i++){
			cont[i] = s[i-1]-'A';
		}
		f(m){
			char a,b;
			cin >> a >> b;
			op[i][0] = a-'A';
			op[i][1] = (b=='R') - (b=='L');
		}
		int rb=0;
		for(int i=1<<20;i;i>>=1){
			int now=rb+i;
			if(now>n)continue;
			int pos=now;
			for(int j=0;j<m;j++){
				if(cont[pos]==op[j][0]){
					pos+=op[j][1];
				}
				//cout << pos << endl;
				if(pos>n){
					rb -= i;
					break;
				}
			}

			rb += i;
		}
		int lb=0;
		for(int i=1<<20;i;i>>=1){
			int now=lb+i;
			if(now>n)continue;
			int pos=n-now;
			for(int j=0;j<m;j++){
				if(cont[pos]==op[j][0]){
					pos+=op[j][1];
				}
				if(pos<1){
					lb -= i;
					break;
				}
			}
			lb += i;
		}
		if(!lb||!rb){
			cout<<0<<endl;
			exit(0);
		}
		lb = n-lb;
		//cout<<rb<<' '<<lb<<endl;
		cout<<max(0,rb-lb+1)<<endl;
	}
}