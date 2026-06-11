#include <bits/stdc++.h>    
#define pb push_back

#define FOR(x,to) for(int x=0;x<(to);x++)
#define F0R(x,in,to) for(int x=(in);x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))

typedef long long ll;
using namespace std;
ll MOD = 998244353;

typedef pair<int,int> ii;
typedef struct {int a,b,c;}iii;
typedef vector<int> vi;

void mosA(vector<int> a){
	for(int i=0; i<a.size(); i++) printf("%d ",a[i]);
	printf("\n");
}
void mosP(vector<ii> a){
	for(int i=0; i<a.size(); i++) printf("%d %d\n",a[i].first,a[i].second);
	printf("\n");
}

ll min_especial(ll a, ll b){
  if(a!=-1 && b!=-1) return min(a,b);
  else return max(a,b);
}
/*
bool ord(ii a, ii b){
	if(a.first == b.first){
		return a.second < b.second;
	}
	return a.first < b.first;
}*/

bool ord(ll a, ll b){
	return a>b;
}

int ans = 0;
int a,n,nn,w,t,k,m,z,q,l,r,x,b,y;
char A[200005],B[200005];

int main(){
	scanf("%d%d%d",&n,&m,&nn);
	int f,c;
	scanf("%d%d",&f,&c);
	scanf(" %s %s",A,B);

	

	for(int i=0, cont = c; i<nn; i++){
		if(A[i] == 'R')cont++;
		//cout<<cont<<endl;
		if(cont>m) return !printf("NO");
		if(B[i] == 'L')cont=max(1,cont-1);
	}

	for(int i=0, cont = c; i<nn; i++){
		if(A[i] == 'L')cont--;
		if(cont<1) return !printf("NO");
		if(B[i] == 'R')cont=min(m,cont+1);
	}

	for(int i=0, cont = f; i<nn; i++){
		if(A[i] == 'U')cont--;
		if(cont<1) return !printf("NO");
		if(B[i] == 'D')cont=min(n,cont+1);
	}

	for(int i=0, cont = f; i<nn; i++){ 	 	
		if(A[i] == 'D')cont++;
		if(cont>n) return !printf("NO");
		if(B[i] == 'U')cont=max(1,cont-1);
	}

	return !printf("YES");

}




// REVISATE ESTO:
// - memset(A,-1,SIZEOF()*n)
// - (x-y+MOD)%MOD
// - int o ll?