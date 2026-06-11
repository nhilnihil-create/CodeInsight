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
//桁数把握
ll keta(ll a){
	ll count=0;
	while(a!=0){
		a=a/10;
		count++;
	}
	return count;
}
int main()
{
	ll N,M,ANS=0;
	vector<pair<ll,ll>>V;
	cin>>N>>M;
	rep(i,N){
		pair<ll,ll>t;
		cin>>t.first>>t.second;
		V.push_back(t);
	}
	sort(V.begin(),V.end());
	rep(i,N){
		for(;;){
			V[i].second--;
			M--;
			ANS=ANS+V[i].first;
			if(V[i].second==0||M==0)break;
		}
		if(M==0)break;
	}
	cout<<ANS<<endl;
}