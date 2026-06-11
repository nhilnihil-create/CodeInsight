#include <iostream>
#include <vector>
#define rep(i,N) for(int i=0; i < (N); i++)
using namespace std;

int main(){
	long long N;
	cin>>N;
	vector<long long> t(N+1),x(N+1),y(N+1);
	t[0]=0;
	x[0]=0;
	y[0]=0;
	for(int i = 1; i <= N; i++) cin>>t[i]>>x[i]>>y[i];

	long long Dt,Dl;
	for(int i = 0; i<N ; i++){
		Dt = t[i+1] - t[i];
		Dl = abs(x[i+1] - x[i]) + abs(y[i+1] - y[i]);

		if(Dt - Dl < 0){
			cout<<"No"<<endl;
			break;
		}else if( (Dt - Dl) % 2 != 0 ){
			cout<< "No"<<endl;
			break;
		}
		if(i==N-1){
			cout<<"Yes"<<endl;
		}
	}
}