#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<ll> vi;
typedef long double td;
typedef vector<td> vd;
typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = ll(a); i < (ll)(b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define show(v,n) cerr << #v << " = "; forn(i,n) cerr << v[i] << " "; cerr << endl;
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
int MAXN = 500005;
int INF = (int)(1e9+7);

struct flower
{
	ll h, b;
};

vector <ll> tree(4*MAXN,0);

void actualizar(int pos)
{
	tree[pos]=max(tree[2*pos+1],tree[2*pos+2]);
}
 
ll mayor_segtree(int a, int b, int x, int y, int pos)
{
  if(x>b || y<a) return 0LL;
  if(x<=a && b<=y) return tree[pos];
  int med=(a+b)/2;
  return max(mayor_segtree(a,med,x,y,2*pos+1),mayor_segtree(med+1,b,x,y,2*pos+2));
}
 
void modificar_segtree(int a, int b, int pos, int y, ll m)
{
  if(a==b) {tree[pos]=m; return;}
  int med=(a+b)/2;
  if(y<=med) modificar_segtree(a,med,2*pos+1,y,m);
  else modificar_segtree(med+1,b,2*pos+2,y,m);
  actualizar(pos);
}
 
void construir_segtree(int a, int b, int pos, vector <ll> &v)
{
  if(a==b) {tree[pos]=v[a]; return;}
  int med=(a+b)/2;
  construir_segtree(a,med,2*pos+1,v);
  construir_segtree(med+1,b,2*pos+2,v);
  actualizar(pos);
}

void construir(vector <ll> &v, int n)
{
	construir_segtree(0,n-1,0,v);
}

void modificar(int pos, ll val, int n)
{
	modificar_segtree(0,n-1,0,pos,val);
}

ll mayor(int l, int r, int n)
{
	return mayor_segtree(0,n-1,l,r,0);
}
 
int main()
{ 	
	FIN;
	#ifdef input
		freopen("T3.txt", "r", stdin);
	#endif
	
	int n;
	cin >> n;
	vector <flower> v(n);
	forn(i,n) cin >> v[i].h;
	forn(i,n) cin >> v[i].b;
	ll ans = 0;
	forn(i,n)
	{
		ll aux = mayor(0,v[i].h-1,n);
		ans = max(ans,aux+v[i].b);
		modificar(v[i].h,aux+v[i].b,n);
	}
	cout << ans << "\n";
	
	
    return 0;
}
