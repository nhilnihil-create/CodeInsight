#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pb push_back
#define ld long double
#define pii pair<int,int>
#define sz(x) (int)x.size()
#define piii pair<pii,pii>
#define precise cout<<fixed<<setprecision(10)
#define st first
#define nd second
#define ins insert
#define vi vector<int>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int MAX=8010;
const int STALA=8002;
bitset<MAX*2>dpx[MAX];
bitset<MAX*2>dpy[MAX];
string s;
vi noms;
int32_t main()
{
  BOOST;
  int dir=0;
  int lx=0,ly=0;
  dpx[0][STALA]=true;
  dpy[0][STALA]=true;
  cin>>s;
  for (int i=0;i<sz(s);){
  	int j=i;
  	int licznik=0;
  	while (s[j]=='F')j++,licznik++;
  	i=max(i+1,j);
  	if (licznik)noms.pb(licznik);
  	else noms.pb(-1);
  }
  for (auto it:noms){
  	if(it==-1){
  		dir++;
  	} 
  	else{
  		if (dir==0){
  			lx++;
  		  for (int j=2*STALA;j>=0;j--){
  		  	if (dpx[lx-1][j])dpx[lx][j+it]=true;
  		  }
  		}
  		else if (dir%2==0){
  			lx++;
  		//	cout<<"TERAZ "<<it<<"\n";
  			for (int j=2*STALA;j>=0;j--){
  		  	if (dpx[lx-1][j] && j+it<=2*STALA)dpx[lx][j+it]=true;
  		  }
  		  
  		  for (int j=1;j<=STALA*2;j++){
  		  	if (dpx[lx-1][j] && j-it>=0)dpx[lx][j-it]=true;
  		  }
  		}
  		else{
  			ly++;
  			for (int j=2*STALA;j>=0;j--){
  		  	if (dpy[ly-1][j] && j+it<=2*STALA)dpy[ly][j+it]=true;
  		  }
  		  
  		  for (int j=1;j<=STALA*2;j++){
  		  	if (dpy[ly-1][j] && j-it>=0)dpy[ly][j-it]=true;
  		  }
  		}
  	}
  }
  int x,y;
  cin>>x>>y;
  if (dpx[lx][STALA+x] && dpy[ly][STALA+y])cout<<"Yes";
  else cout<<"No";
  return 0;
}