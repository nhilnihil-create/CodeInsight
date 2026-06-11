#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <istream>
#include <sstream>
#include <cctype>
#include <iomanip>
//cout << fixed << setprecision(20) << *** << endl;
#define rep(i,N) for(int i=0;i<(int)N;++i)
typedef long long ll;
using namespace std;

int main()
{
	ll N,K,KK;
	vector<ll>V(3,0);
	cin>>N>>K;
	V[2]=K/1000;
	for(;;){
		//cout<<V[0]<<":"<<V[1]<<":"<<V[2]<<endl;
		if(V[0]+V[1]+V[2]==N){
			cout<<V[0]<<" "<<V[1]<<" "<<V[2]<<endl;
			return 0;
		}
		if(V[2]>=5){
			V[2]-=5;
			V[1]++;
		}
		else if(V[1]!=0){
			V[1]-=2;
			V[0]++;
			if(V[1]!=0){
				V[2]=V[2]+V[1]*5;
				V[1]=0;
			}
		}
		else break;
	}
	cout<<"-1 -1 -1"<<endl;
}