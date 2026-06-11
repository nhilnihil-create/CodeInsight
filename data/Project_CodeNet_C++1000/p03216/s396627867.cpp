#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int N,Q;
  string S;
  cin >> N >> S >> Q;
  vector<int> k(Q);
  for(int i=0;i<Q;i++){
	cin >> k[i];
  }

  for(int j=0;j<Q;j++){
	long long D=0,M=0,DM=0,DMC=0;
	for(int i=0;i<N;i++){
	  if(S[i]=='D'){
		D++;
	  }
	  if(S[i]=='M'){
		DM+=D;
		M++;
	  }
	  if(S[i]=='C'){
		DMC+=DM;
	  }
	  if(i-k[j]+1>=0){
		if(S[i-k[j]+1]=='D'){
		  D--;
		  DM-=M;
		}if(S[i-k[j]+1]=='M'){
		  M--;
		}
	  }
	}
	cout << DMC << endl;
  }
  
  
  return 0;
}
