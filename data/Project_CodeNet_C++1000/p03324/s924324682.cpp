#include <bits/stdc++.h>
#include<string>
using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair<int,int> pi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define re(i,a,b) for(ll i=a;i<b;i++)
//add below to remove endl in input just before getline()
//cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
int main(){
	//ios::sync_with_stdio(0);cin.tie(0);
	//freopen("input.txt", "r", stdin);
	int d,n,c=0;
	cin>>d>>n;
	for(int i=0;;i++){
		if(i%100!=0){
			c++;
			if(c==n){cout<<i;break;}
			}
		}
		if(d==1)cout<<"00";
		else if(d==2)cout<<"0000";

	
return 0;}
