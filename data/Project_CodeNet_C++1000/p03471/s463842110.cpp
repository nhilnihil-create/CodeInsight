#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
 
int main() {
  long long N,Y;
	cin>>N>>Y;
	rep(i,N+1){
		rep(j,N+1){
			rep(k,N+1){
				if(i+j+k==N && 10000*i+5000*j+1000*k==Y){
				  cout<<i<<" "<<j<<" "<<k<<endl;
					return 0;
				}
				if(i+j+k>N) break;
			}
			if(i+j>N) break;
		}
	}
	cout<<-1<<" "<<-1<<" "<<-1<<endl;
	return 0;
}