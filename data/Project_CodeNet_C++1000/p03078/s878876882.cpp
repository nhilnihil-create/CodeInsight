#include <bits/stdc++.h>
using namespace std;

int main(){
	int X,Y,Z,K;
	cin >> X >> Y >> Z >> K;
	vector<long long> A(X),B(Y),C(Z);
	for(auto &i:A)cin >> i;
	for(auto &i:B)cin >> i;
	for(auto &i:C)cin >> i;
	sort(A.begin(),A.end(),greater<long long>());
	sort(B.begin(),B.end(),greater<long long>());
	sort(C.begin(),C.end(),greater<long long>());
	
	vector<long long> AB;
	for(int i=0;i<min(K,X);i++)for(int j=0;j<min(K,Y);j++){
		AB.push_back(A[i]+B[j]);
	}
	
	sort(AB.begin(),AB.end(),greater<long long>());
	int XY=AB.size();
	
	vector<long long> ABC;
	for(int i=0;i<min(K,XY);i++)for(int j=0;j<min(K,Z);j++){
		ABC.push_back(AB[i]+C[j]);
	}
	
	sort(ABC.begin(),ABC.end(),greater<long long>());
	for(int i=0;i<K;i++)cout << ABC[i] << endl;
	
	return 0;
}