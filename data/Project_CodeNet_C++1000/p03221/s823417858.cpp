#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i,N) for(int i=0;i<(N);i++)
using namespace std;

int main(){
	long long N,M;
	cin>>N>>M;
	vector<long long> P(M),Y(M);
	rep(i,M)cin>>P[i]>>Y[i],--P[i];
	vector< vector<long long> > city(N);
	rep(i,M)city.at(P[i]).push_back(Y[i]);
	rep(i,N){
		sort(city.at(i).begin(), city.at(i).end());
	}
	rep(i,M){
		int cityNum=P[i];
		printf("%06d",cityNum+1);
		//Y[i]はcity[P[i]]の始まりからどれだけ進んだかを表す
		int id = lower_bound(city.at(cityNum).begin(), city.at(cityNum).end(), Y[i]) - city.at(cityNum).begin();
		printf("%06d\n",id+1);
	}
}