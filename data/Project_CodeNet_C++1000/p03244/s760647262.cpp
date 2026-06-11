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
	int n;
	cin >> n;
	int a;
	std::vector<int> even;
	std::vector<int> odd;
	FOR(i,n) {
		cin >> a;
		if(i%2) odd.eb(a);
		else even.eb(a);
	}
	sort(odd.begin(),odd.end());
	sort(even.begin(),even.end());
	int maxe=0; int me=-1;
	int maxo=0; int mo=-1;
	int i=0;
	while(i < n/2){
		int j=i;
		while(j < n/2 &&even[j]==even[i]) j++;
		if(j-i > maxe){
			maxe=j-i;
			me=even[i];
		}
		i=j;
	}
	i=0;
	int maxe2=0; int me2=-1;
	int maxo2=0; int mo2=-1;
	while(i < n/2){
		int j=i;
		while(j < n/2 && even[j]==even[i])j++;
		if(j-i > maxe2 && even[i]!=me){
			maxe2=j-i;
			me2=even[i];
		}
		i=j; 
	}
	int k=0;
	while(k < n/2){
		int j=k;
		while(j < n/2 && odd[j]==odd[k]) j++;
		if(j-k > maxo){
			maxo=j-k;
			mo=odd[k];
		}
		k=j;
	}
	k=0;
	while(k < n/2){
		int j=k;
		while(j < n/2 && odd[j]==odd[k]) j++;
		if(j-k > maxo2 && odd[k]!=mo){
			maxo2=j-k;
			mo2=odd[k];
		}
		k=j;
	}
	
	if(me!=mo){
		cout << n- maxe  -maxo;
	}
	else{
		cout << min(n-maxe-maxo2, n-maxe2-maxo);
	}
	return 0;
}