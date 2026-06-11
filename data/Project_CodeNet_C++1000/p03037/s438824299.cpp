#include <iostream>
#include <vector>
#include<string>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
	int N;
	int M;
	cin >> N >> M;
	vector<int>L(M);
	vector<int>R(M);
	
	for(int i = 0;i<M;i++){
		cin >> L[i]>> R[i];
	}	
	
	int Lmax = 0;
	int Rmin = 1000001;
	
	for(int i = 0;i<M;i++){
		if(Lmax<L[i]){
			Lmax = L[i];
		}
		if(Rmin>R[i]){
			Rmin = R[i];
		}
	}
	
	int ans = Rmin - Lmax + 1;
	
	if(ans>0){
		std::cout << ans <<endl; 	
		return 0;
	}else{
		std::cout << "0" <<endl; 	
		return 0;
	}
	
}