#include "bits/stdc++.h"

#define sp <<" "
#define el <<"\n"
#define S second
#define F first
#define mp make_pair
#define pb push_back
#define pf push_front
#define pob pop_back
#define obit __builtin_popcount
#define pof pop_front
#define mod (int)1e9 + 7
#define For(i,a,n) for(i=a;i<n;i++)

using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef unsigned short int us;
typedef short int ss;
typedef long double ld;

void pre(int* ar,int n,string st){
	int i,cnt = 0;
	ar[0] = cnt;
	For(i,0,n-1){
		string demo = string(st.begin()+i,st.begin()+i+2);
		if(demo == "AC") cnt++;
		//cout<<demo el;
		ar[i+1] = cnt;
	}
	return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
/*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif*/
    int n,q,i;
    string st;
    cin>>n>>q>>st;
    int ar[n];
    pre(ar,n,st);
    //for(int t: ar) cout<<t sp;
    //cout el;
    For(i,0,q){
    	int l,r;
    	cin>>l>>r;
    	r-= 1; l-= 1;
    	//cout<<l sp<< r <<": ";
    	cout<<ar[r] - ar[l] el;
    }
    return 0;
}
