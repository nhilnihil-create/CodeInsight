#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	int n;
	cin>>n;
	long long aoki=0;
	vector<long long> meal(n);

	for(int i=0;i<n;i++){
		long long a,b;
		cin>>a>>b;

		aoki-=b;

		meal.at(i)=a+b;
	}

	sort(meal.begin(),meal.end());
	reverse(meal.begin(),meal.end());

	for(int i=0;i<n;i+=2){
		aoki+=meal.at(i);
	}

	cout<<aoki<<endl;

	return 0;
}
