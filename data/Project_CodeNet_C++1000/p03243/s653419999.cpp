# include<bits/stdc++.h> 
#define ll long long
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string s;
	int n;
	bool f = 0;
	cin>>n;
	int r = 111;
	for(int i = 1; i<10; i++)
		if(r*i >= n){
		 cout<<r*i<<'\n';
		 break;
		}
}
