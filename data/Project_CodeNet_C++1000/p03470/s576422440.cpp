#include <iostream>
#include <vector>

using namespace std;

int main(){
  	int N;
  	int max = 101;
  	cin >> N;
  	vector<int> d(N),flag(max);
  	for(int i=0;i<N;i++){
      	cin >> d[i];
      	flag[d[i]] = 1;
    }
  	int res=0;
  	for(int i=0;i<max;i++){
      	if(flag[i]) res++;
   	}
  	cout << res << endl;  	
}