#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define what_is(x) cerr << #x << " is " << x << endl;
#define MT make_tuple
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i,n) for (int i=0;i < n ; i++)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
clock_t startTime;
long double getTime(){
	return (long double)(clock()-startTime)/CLOCKS_PER_SEC;
}

int main(){
	startTime=clock();
	int h,w;
	cin >> h >> w;
	int a[h][w];
	std::vector<tuple<int,int,int,int>> v;
	int n=0;
	FOR(i,h){
		int count=0;
		FOR(j,w){
			cin >> a[i][j];
			a[i][j]+=count;	
			count=0;
			if(j!= w-1 && a[i][j]%2==1){
				v.PB(MT(i+1,j+1,i+1,j+2));
				count++;
				n++;
				a[i][j]--;
			}

		}
	}
	
	

	cout <<"\n";

	FOR(i,h-1){
		if(a[i][w-1]%2){
			a[i][w-1]--;
			v.PB(MT(i+1,w,i+2,w));
			a[i+1][w-1]++;
			n++;
		}
	}

	

	cout << n <<"\n";
	for(auto x : v){
		cout << get<0>(x) << " "<< get<1>(x)<<" " ;
		cout << get<2>(x) << " " <<get<3>(x)<<"\n";
	}

	


	return 0;
}