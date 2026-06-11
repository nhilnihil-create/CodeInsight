#include<bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define REP(ii,aa,nn) for(long long int ii=(aa);(ii)<=(nn);(ii)++)
 
typedef vector<int> vi;
typedef long long int ll;


int main(){
ll r,d,x;cin>>r>>d>>x;

		REP(i,0,9){
			
			x=r*x-d;
			
			if(x<0)
			cout<<0<<endl;
			else
			cout<<x<<endl;
			
		}
	return 0;
}
