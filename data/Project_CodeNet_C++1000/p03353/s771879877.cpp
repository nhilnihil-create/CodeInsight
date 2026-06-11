#include <iostream>
//#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
//#include <utility>
#include <set>
//#include <map>
//#include <queue>
//#include <deque>
//#include <bitset>
//#include <math.h>
using namespace std ;
//using ll = long long ;
//using ld = long double ;
//using vll = vector<ll> ;
//using vvll = vector<vll> ;
//using vc = vector<char> ;
//using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
//using pll = pair<ll,ll> ;

//ll mod = 1000000007 ;
//long double pie = acos(-1) ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}

int main(){
	string s ; cin >> s ;
	int k ; cin >> k ;
	set<string> ok ;
	vector<string> vec ;
	int n = s.size() ;
	for(int i=0;i<n;i++){
		string t ;
		for(int j=i;j<n;j++){
			t += s.at(j) ;
			if(vec.size()<5&&!ok.count(t)){
				vec.push_back(t) ;
				ok.insert(t) ;
				sort(vec.begin(),vec.end()) ;
			}
			if(!ok.count(t)&&t<vec.at(vec.size()-1)){
				ok.insert(t) ;
				vec.push_back(t) ;
				sort(vec.begin(),vec.end()) ;
				vec.pop_back() ;
			}
		}
	}
	sort(vec.begin(),vec.end()) ;
	cout << vec.at(k-1) << endl ;
}
