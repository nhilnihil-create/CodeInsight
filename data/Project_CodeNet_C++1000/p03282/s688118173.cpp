#include <iostream>
#include <cstring>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>

 
using namespace std;

typedef long long ll;
typedef long double ld;
#define L(ID) ((ID*2)+1)
#define R(ID) ((ID*2)+2)
#define M(L,R) ((L+R)/2)
#define forr(start,end) for(int i = start; i < end; i++)
#define gap ' '
 
const int MAXN = 100 + 5;
char s[MAXN];
ll n, t, k;

ll largest(ll a, ll b){
	return (a<b)?b:a;
}
ll smallest(ll a, ll b){
	if(a < b)return a;
	return b;
}


int main(){
	cin >> s >> k;
	bool isone = true;
	for(int i = 0; i < k; ++i){
		if(s[i] != '1'){
			isone = false;
			break;
		}
	}
	if(isone){
		cout << '1' << endl;
		return 0;
	}
	if(k == 1){
		cout << s[0] << endl;
		return 0;
	}
	for(int i = 0; i < strlen(s); ++i){
		if(s[i] != '1'){
			cout << s[i] << endl;
			return 0;
		}
	}
	cout << '1' << endl;

    return 0;
}
