#include <iostream>
#include <vector>
#include <algorithm>

#define lli long long int
#define REP(i,n) for(lli i=0;i<n;i++)

using namespace std;

lli calc(lli n){
	lli ans=0;
	while(n){
		ans += n%10;
		n/=10;
	}
	return ans;
}

double g(long long n){
	return (double)(n)/calc(n);
}

int main(){

	vector<lli> res;
	lli base=1;

	//10^15まで候補を全部列挙*/
	for(lli i=0;i<15;i++){
		for(lli j=1;j<150;j++){
			res.push_back(base*(j+1)-1);
		}
		base*=10;
	}

	sort(res.begin(),res.end());
	res.erase(unique(res.begin(),res.end()),res.end());

	//だめなやつを除く
	for(lli i=0;i<res.size();i++){
		for(lli j=i+1;j<res.size();j++){
			if(g(res[i])>g(res[j])){
				res.erase(res.begin()+i--);
				break;
			}
		}
	}

	lli k;
	cin>>k;
	REP(i,k){
		cout<<res[i]<<endl;
	}

	return 0;

}