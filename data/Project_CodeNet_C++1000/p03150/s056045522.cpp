#include<bits/stdc++.h>
#define fo(i,a,b) for((i)=(a);i<=(b);i++)
#define rfo(i,a,b) for((i)=(a);i>=(b);i--)
#define inrange(x,y,z) (((x)>=(y))&&((x)<=(z)))
#define ALL(vec) ((vec).begin(),(vec).end())
#define SOR(vec) sort(ALL(vec))
#define UNI(vec) (vec).erase(unique(ALL(vec)),(vec).end())
using namespace std;
string s,l,r;
int n;
int main(){
	#ifdef FILIN
		#ifndef DavidDesktop
			freopen(FILIN,"r",stdin);
			freopen(FILOUT,"w",stdout);
		#endif
	#endif
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>s;
	n=s.size();
	for(int lef=0;lef<n;lef++){
		for(int rig=lef;rig<=n;rig++){
			l=s.substr(0,lef);
			r=s.substr(rig);
			if(l+r=="keyence"){
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
