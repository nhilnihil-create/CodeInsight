#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
#define loop(n) for(int i=0; i<n; i++)
#define rep(i,start,n) for(int i=start; i<n; i++)

signed main(){
    fast;  

    int t[3][3];
    int a[3]={0},b[3]={0};

    loop(3)
    rep(j,0,3){
    	cin>>t[i][j];
    	if(i==0)b[j]=t[i][j];
    }

    a[1]=t[1][0]-b[0];
    a[2]=t[2][0]-b[0];

    loop(3)
    rep(j,0,3){
    	if(t[i][j]!=a[i]+b[j]){
    		cout<<"No"<<endl;
    		return 0;
		}
    }

    cout<<"Yes"<<endl;
    return 0;
}
