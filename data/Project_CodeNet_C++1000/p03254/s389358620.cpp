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
	ll N,x,ANS=0,sum=0;
	vector<ll>V;
	cin>>N>>x;
	rep(i,N){
		ll t;
		cin>>t;
		V.push_back(t);
		sum=sum+t;
	}
	sort(V.begin(),V.end());
	if(sum==x){
		cout<<N<<endl;
	}
	else if(sum<x){
		cout<<N-1<<endl;
	}
	else{
		for(ll i=0;i<N;i++){
			x=x-V[i];
			ANS++;
			if(x==0)break;
			if(x<0){
				ANS--;
				break;
			}
		}
		cout<<ANS<<endl;
	}

}