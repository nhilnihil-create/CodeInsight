#include <iostream>
using namespace std;
int main(){
	int N,A,B;
	cin >> N >> A >> B;
	
	int ans=0;
	int total;
	for(int n=1;n<=N;n++){
		total = n%10 + (n%100-n%10)/10 + (n%1000-n%100)/100 + (n%10000-n%1000)/1000 + (n%100000-n%10000)/10000;
		if(total>=A && total<=B){
			ans+=n;
		}
	}
	cout << ans << endl;
	return 0;
}