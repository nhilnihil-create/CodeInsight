#include <bits/stdc++.h>
using namespace std;
// std::vector<long long int> ;
long long int getMoves(long long int b,long long int a){
     return b-a;
}
int main() {
	string a;
	cin >> a;
// 	cout << a;
	long long int k = 0;
	long long int st = 0;
	long long int ans = 0;
	for(long long int i=0;i<a.size();i+=1){
	    // cout << a[i];
          if(a[i]=='W' && k==1 ){
               ans+=getMoves(i,st);
               st+=1;
          }
          if(a[i]=='W' && (i-st)<=1 && k==0){
               st = i+1;
          }
          if(a[i]=='B'){
               k=1;
          }
	}
	cout << ans;
}
