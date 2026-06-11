#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
const int mod = (int)1e9 + 7;
void dbg(){ cerr << "\n"; }  template <typename T,typename ...T2> 
void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
const int dr[]={0,1,0,-1,0};

int main(){
	int n;
	cin >>n;
	
	map<int,int> mp;
	for(int i=1; i<=n && i*(i+1) <= 2*n;i++){
		mp[i*(i+1) / 2] = i;
	}
	//for(auto x :mp) printf("%d:%d, ",x.first,x.second); puts("");
	if( !mp.count(n)){ puts("No"); return 0;}
	int  no = mp[n];
	
	vector<VI> zs(no+1, VI(no, -1));
	auto it=mp.begin(); 
	zs[0][0]= zs[1][0] =1;
	for(auto x: mp){
		int i=x.second - 1;
		int c= x.first;
		repr(j,i,0){
			zs[i+1][j] = zs[j][i] = c--;
		}
	}
	
	//for(auto xl: zs){for(auto x :xl) printf("%2d, ",x); puts("");}

	puts("Yes");
	printf("%d\n", no+1);
	for(auto xl: zs){
		printf("%d ", no);
		for(auto x :xl) printf("%d ",x);
		puts("");
	}
}

