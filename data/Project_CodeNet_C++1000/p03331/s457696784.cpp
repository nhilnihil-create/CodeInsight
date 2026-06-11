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

ll sum_keta(ll a){
	ll A=a,SUM=0;
	while(A!=0){
		SUM=SUM+A%10;
		A=A/10;
	}
	return SUM;
}

int main()
{
	ll N,A,B;
	vector<ll>V;
	cin>>N;
	A=1;
	B=N-1;
	for(;;){
		ll sum=0;
		sum=sum_keta(A)+sum_keta(B);
		V.push_back(sum);
		if(A==B&&N%2==0)break;
		if(A-B==-1&&N%2==1)break;
		A++;
		B--;
	}
	sort(V.begin(),V.end());
	cout<<V.front()<<endl;
}