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
	string s,t;
	cout << 0<<endl;
	cin >> s;
	if(s=="Vacant") return 0;

	
	int p=1;
	int q=n-1;
	cout << p<<endl;
	cin >> s;
	if(s=="Vacant") return 0;
	cout << q<<endl;
	cin >> t;
	if(t=="Vacant") return 0;
	int mid;
	string aux;
	int i=0;
	while(1){
		mid=p+(q-p)/2;
		cout <<  mid << endl;
		cin >> aux;
		if(aux=="Vacant") return 0;
		if(mid%2==p%2){
			if(aux==s) {
				p=mid+1;
				s=(aux=="Male")? "Female": "Male";
			}
			else{
				q=mid-1;
				t=(aux=="Male")?"Female":"Male";	
			} 
		}
		else{
			if(aux==s){
				q=mid-1;
				t=(aux=="Male")? "Female":"Male";
			}
			else{
				p=mid+1;
				s=(aux=="Male")? "Female": "Male";				
			}
		}
		//error(p,q,mid,aux);
	}

	return 0;
}