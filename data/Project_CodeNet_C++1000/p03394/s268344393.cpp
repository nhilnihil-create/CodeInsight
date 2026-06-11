#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define ppb pop_back
#define ppf pop_front
#define umax(x,y) x=max(x,y)
#define umin(x,y) x=min(x,y)
#define ll long long
#define ii pair<int,int>
#define iii pair<ii,int>
#define iiii pair<ii,ii>
#define sz(x) ((int) x.size())
#define orta ((bas+son)/2)
#define all(x) x.begin(),x.end()
#define dbgs(x) cerr<<(#x)<<" --> "<<(x)<<" "
#define dbg(x) cerr<<(#x)<<" --> "<<(x)<<endl;getchar()
#define pw(x) (1<<(x))
#define inf 1000000000
#define MOD 1000000007
#define N 500005
#define M 27000
#define LOG 21
#define KOK 650
#define EPS 0.00001
using namespace std;

vector<int> k2,k3,k6;
int n;

int main() {

//	freopen("input.txt","r",stdin);

//	freopen("curling.gir","r",stdin);
//	freopen("curling.cik","w",stdout);

	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	for(int i=1;i<=30000;i++) {

		if(i%6==0) {

			k6.pb(i);

		}
		else if(i%3==0) {

			k3.pb(i);

		}
		else if(i%2==0) {

			k2.pb(i);

		}

	}

	cin>>n;

	if(n>=5) {

		int tot3=2,tot2=2;

		for(int i=0;i<tot3;i++) cout<<k3[i]<<" ";

		for(int i=0;i<tot2;i++) cout<<k2[i]<<" ";

		n-=tot3+tot2;
		
		while(n>sz(k6)) {

			if(tot3+2<sz(k3)) {

				for(int i=tot3;i<tot3+2;i++) cout<<k3[i]<<" ";

				tot3+=2;
				n-=2;

			}
			else if(tot2+2<sz(k2)) {

				for(int i=tot2;i<tot2+2;i++) cout<<k2[i]<<" ";

				tot2+=2;
				n-=2;

			}
			else {

				for(int i=tot3;i<sz(k3);i++) {cout<<k3[i]<<" ";n--;}

				for(int i=tot2;i<sz(k2);i++) {cout<<k2[i]<<" ";n--;}

			}

		}

		for(int i=0;i<n;i++) cout<<k6[i]<<" ";
	
	}
	else {

		if(n==3) {

			cout<<"2 5 63";

		}
		else {

			cout<<"2 5 20 63";

		}

	}

}

