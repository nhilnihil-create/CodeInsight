#include<iostream>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;
typedef long long ll;

const double eps=1e-7;

int main(){
	ll in;
	cin>>in;
	double tmp,ue,sita;
	bool check=false;
	loop(i,1,3501){
		loop(j,1,3501){
			ue=in*i*j;
			sita=4*i*j-in*i-in*j;
			tmp=ue/sita;
			if(tmp-(int)tmp<eps&&tmp>=1&&tmp<=3500){
				cout<<i<<" "<<j<<" "<<(int)tmp<<endl;
				check=true;
				break;
			}
		}
		if(check)break;
	}
	return 0;
}