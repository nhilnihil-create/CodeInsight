#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define maxn 1000000
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pp;
struct edge{
	int u,v,c;
};
int n,m,x,orix; vector <edge> t;
void PrintAns(int so){
	int i,j;
	cout<<"20 "<<t.size()<<'\n';
	for (i=0;i<t.size();i++){
		edge e=t[i]; if (e.v==so) e.v=20;
		cout<<e.u<<' '<<e.v<<' '<<e.c<<'\n';
	}
	exit(0);
}
void thu3(){
	int i,j,dem=1,ed=0; edge e; bool ok=false;
	if (x>=2) ok=true;
	while (ok&&x>=2){
		if (x>2&&x%3!=2){
			while (x%3!=2){
				ed++; 
				e.u=dem; e.v=20; e.c=x;
				t.pb(e); x--;
			}
		}
		int newx=x/3;
		ed+=3; 
		e.u=dem; e.v=dem+1; e.c=0; t.pb(e);
		e.u=dem; e.v=dem+1; e.c=newx+1; t.pb(e);
		e.u=dem; e.v=dem+1; e.c=2*newx+2; t.pb(e);
		x=newx; dem++;
	}
	if (x==0&&ed<=60&&dem<=20){
		PrintAns(dem); exit(0);
	}
	while (x>=0){
		ed++; e.u=dem; e.v=dem+1; e.c=x; 
		t.pb(e); x--;
	}
	dem++;	
	if(ed<=60&&dem<=20){
		PrintAns(dem); exit(0);
	}
}
void thu4(){
	int i,j,dem=1,ed=0; edge e; bool ok=false;
	if (x>=3) ok=true;
	while (ok&&x>=3){
		if (x>3&&x%4!=3){
			while (x%4!=3){
				ed++; 
				e.u=dem; e.v=20; e.c=x;
				t.pb(e); x--;
			}
			
		}
		int newx=x/4;
		ed+=4; 
		e.u=dem; e.v=dem+1; e.c=0; t.pb(e);
		e.u=dem; e.v=dem+1; e.c=newx+1; t.pb(e);
		e.u=dem; e.v=dem+1; e.c=2*newx+2; t.pb(e);
		e.u=dem; e.v=dem+1; e.c=3*newx+3; t.pb(e);
		x=newx; dem++;
	}
	if (x==0&&ed<=60&&dem<=20){
		PrintAns(dem); exit(0);
	}
	while (x>=0){
		ed++; e.u=dem; e.v=dem+1; e.c=x; 
		t.pb(e); x--;
	}
	dem++;	
	
	if(ed<=60&&dem<=20){
		PrintAns(dem); exit(0);
	}
}
main(){
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen(".inp","r",stdin); freopen(".out","w",stdout);
	//freopen("inp.txt","r",stdin);
	cin>>x; x--; orix=x;
	thu3(); 
	x=orix; t.clear(); 
	thu4();
}