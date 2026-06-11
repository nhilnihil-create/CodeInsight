#include <iostream>
using namespace std;

int main(){
  	int N;
  	cin >> N;
  	int Mc = N/4+1;
  	int Md = N/7+1;
  	for(int i=0;i<Mc;i++){
      	for(int j=0;j<Md;j++){
          	if(i*4+j*7 == N){
              	cout << "Yes" << endl;
              	return 0;
            }
        }
    }
  	cout << "No" << endl;
}