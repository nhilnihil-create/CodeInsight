#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
// #define endl '\n'
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--) 
#define fast_io ios_base::sync_with_stdio(0);
#define show(x) cout<<x<<endl;
#define pret(x) cout<<x<<endl; return 0;
#define disp(x) cout<<x<<" ";
#define let(x,y) cout<<x<<" "<<y<<endl;
ll MOD=1e9+7;
ll MAX=9223372036854775807;

int f(int n){
	fo(i,1,n){
		int temp = i*(i+1);
		if(temp==n) return i;
		if(temp>n) break;
	}
	return 0;
}

int main(){
    fast_io;
    int n;
    cin>>n;
    int k=f(2*n);
    if(k==0) {
    	pret("No");
    }
    show("Yes");
    show(k+1);
    vi v[k+2];
    fo(i,1,k) v[1].emplace_back(i);
    int temp=k+1;
    fo(i,2,k+1){
    	int flag=0;
    	fo(j,1,i-1){
    		flag++;
    		v[i].emplace_back(v[j][i-2]);
    	}
    	while(flag<k){
    		v[i].emplace_back(temp);
    		temp++;
    		flag++;
    	}
    }
    fo(i,1,k+1){
    	disp(k);
    	for(auto j:v[i]){
    		disp(j);
    	}
    	cout<<endl;
    }
    return 0;
}