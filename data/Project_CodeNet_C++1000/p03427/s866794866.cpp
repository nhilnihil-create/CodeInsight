#include <bits/stdc++.h>
using namespace std;
#define fix(f,n) std::fixed<<std::setprecision(n)<<f
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;
typedef unsigned long long int ull;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a>b)?b:a)
#define max3(a,b,c) ((a>b)?(a>c)?a:c:(b>c)?b:c)
#define min3(a,b,c) ((a<b)?(a<c)?a:c:(b<c)?b:c)
#define REP(i,a,n) for(ll i=a;i<n;i++)
#define pb push_back
#define mp make_pair

ll ds(string x){
    int res=0;
    for(int i=0 ; i<x.length() ; i++){
        res+=x[i]-'0';
    }
    return res;
}

int main(){
	fast;
	int test=1;
	//cin >> test;
	while(test--){
	    string n;
	    cin >> n;
	    int len=n.length();
	    cout << max(ds(n),n[0]-'1'+(len-1)*9);
	}
	return 0;
}