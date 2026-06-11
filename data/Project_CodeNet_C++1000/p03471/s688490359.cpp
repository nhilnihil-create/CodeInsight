#include <iostream>

using namespace std;

#define Nfori(N) for(int i=0;i<(N);i++)
#define Nforj(N) for(int j=0;j<(N);j++)

int main(){
  	int N;
  	long long Y;
  	cin >> N >> Y;
  	Nfori(N+1){
      	Nforj(N+1-i){
          	if(i*10000+j*5000+(N-i-j)*1000 == Y){
              	cout << i << " " << j << " " << N-i-j << endl;
              	return 0;
            }
        }
    }
  	cout << "-1 -1 -1" << endl;
}