#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sidha(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int> 
#define pb push_back

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int r,d,x;cin>>r>>d>>x;
	ll arr[11];
	arr[0]=r*x-d;
	sidha(i,1,10){
		arr[i]=r*arr[i-1]-d;
	}
	sidha(i,0,10){
		cout<<arr[i]<<endl;
	}
	return 0;
}