#include <iostream>
using namespace std;

int main(){
  	int N, A, B;
  	cin >> N >> A >> B;
  	long long res=0;
  	for(int i=0;i<=N;i++){
      	int tmp=i, sum=0;
      	while(1){
          	sum+=tmp%10;
          	if(tmp/10 == 0) break;
          	else tmp/=10;
        }
      	if(A<=sum && sum<=B) res+=i;
    }
  	cout << res << endl;
}