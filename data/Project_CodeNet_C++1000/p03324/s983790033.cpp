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
	if(d==0){
		for(int i=0;;i++){
			if(i%100!=0){
				c++;
				if(c==n){cout<<i;break;}
				}
			}
		}
	else if(d==1){
		for(int i=100;;i+=100){
			if( i%100==0 && (i/100)%100!=0 ){
				c++;
				if(c==n){cout<<i;break;}
				}
			}
		}
	else if(d==2){
		for(int i=10000;;i+=10000){
			if( i%10000==0 && (i/10000)%100!=0 ){
				c++;
				if(c==n){cout<<i;break;}
				}
			}
		}
	

	
return 0;}
