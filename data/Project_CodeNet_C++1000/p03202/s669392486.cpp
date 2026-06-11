//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,a[200000+10];
bool check(int x){
	map<int,int> Fill;
	rb(i,1,n){
		if(i!=1){
			if(a[i]<=a[i-1]){
				if(Fill.end()==Fill.begin()){
					Fill[a[i]]++;
					if(Fill[a[i]]+1>x) return false;
					continue;
				}
				map<int,int> :: IT ite;
				ite=Fill.end();
				ite--;
				while(1){
					if(ite->FIR>a[i]) Fill.erase(ite->FIR);
					else break;
					if(ite==Fill.begin()) break;
					ite--;
				}
				Fill[a[i]]++;
				int L=a[i];
				while(Fill[L]+1>x){
					Fill.erase(L);
					Fill[--L]++;
					
					if(L==0) return false;
				}
			}
		}
	}
	return true;
}
int main(){
	cin>>n;
	rep(i,n) cin>>a[i+1];
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
//		cout<<l<<" "<<r<<endl;
	}
	cout<<l<<endl; 
	return 0;
}