#include<iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <numeric>
typedef long long int ll;
using namespace std;
int main(){ 
	ll N,K,num,num1,count=0;
	cin >> N>>K;
	if(K==0){
		cout<<N*N<<endl;
		return 0;
	}
	for(ll i=K+1;i<=N;i++){
		count+=(i-K)*(N/i)+max((ll)0,(N-i*(N/i))-K+1);
	}
	cout<< count << endl;
	return 0;
}