#include <iostream>
using namespace std;

int k,genap,ganjil;

int main(){
	cin>>k;
	for(int i=0;i<k;i++){
		if(i%2==0){
			genap++;
		}
		if(i%2==1){
			ganjil++;
		}
	}
	cout<<genap*ganjil<<endl;
}

			
