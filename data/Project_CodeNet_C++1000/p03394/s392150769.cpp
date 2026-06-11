#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n==3){
		cout<<2<<" "<<5<<" "<<63<<endl;
	}
	else{
		int thr = 2, eve = n-2;
		while( eve%3 == 1 || eve>15000){
			thr += 2;
			eve -= 2;
		}
		for(int i=0;i<thr;i++){
			cout<<6*i+3<<" ";
		}
		for(int i=1;i<=eve;i++){
			cout<<2*i<<" ";
		}
		cout<<endl;
	}
	return 0;
}