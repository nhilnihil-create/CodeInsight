#include<iostream>
using namespace std;

const int INF=100000000;
int N;
int A[230];

int main(){
 	cin>>N;
  	for(int i=0;i<N;++i)cin>>A[i];
  
  	int res=INF;
  	for(int i=0;i<N;++i){
		int count=0;
      	while(A[i]%2==0){
          A[i]/=2;
          ++count;
        }
     
      if(res>count)res=count;
    }
  
      cout<<res;
  
}
