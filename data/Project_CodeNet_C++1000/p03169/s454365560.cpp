#include<bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define nl cout<<"\n"
#define pb push_back
#define se second
#define fi first
#define int long long 
#define pi pair<int,int>
#define vpi vector<pi>
#define vvpi vector<vpi>
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define For(i,n) for(int i=0;i<n;i++)
#define Forn(i,a,n) for(int i=a;i<n;i++)
#define pie =3.14159265358979323846264338327950;
const int mod= 1e9+7;
	
const int nax= 305;
double p[nax][nax][nax];
double ev[nax][nax][nax];
void solve(){
	fio;
	int n;
	cin>>n;
	vector<int> cnt(4);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		cnt[x]++;
	}
	p[cnt[1]][cnt[2]][cnt[3]]=1.0;
	for(int c=n;c>=0;c--){
		for(int b=n;b>=0;b--){
			for(int a=n;a>=0;a--){
				//cout<<c<<" "<<b<<" "<<a<<endl;
				if(a+b+c==0) continue;
				if(a+b+c>n)continue;
				double waste= (double)(n-a-b-c)/n;
				double e_waste= waste/(1-waste) +1;
				ev[a][b][c]+=e_waste*p[a][b][c];
				if(a){
					double pro= (double)a/(a+b+c);
					p[a-1][b][c]+= p[a][b][c]*pro;
					ev[a-1][b][c]+= ev[a][b][c]*pro;
				}
				if(b){
					double pro= (double)b/(a+b+c);
					p[a+1][b-1][c]+=p[a][b][c]*pro;
					ev[a+1][b-1][c]+= ev[a][b][c]*pro;
				} 
				if(c){
					double pro= (double)c/(a+b+c);
					p[a][b+1][c-1]+=p[a][b][c]*pro;
					ev[a][b+1][c-1]+= ev[a][b][c]*pro;
				}  
			}
		}
	}
	cout.precision(10);
	cout<<fixed<<ev[0][0][0]<<endl;
}

int32_t main(){
	#ifndef ONLINE_JUDGE
  		freopen("input.txt", "r", stdin);
  		freopen("output.txt", "w", stdout);
  	#endif
	int t=1;
	//cin>>t;
	for(int i=1;i<=t;i++){ 
		//cout<<"Case #"<<i<<":\n";
		solve();
	}
	return 0;
}
