#include <iostream>
#include <string>
using namespace std;

int pnjg, j;
string normal1, normal2, kebalik1, kebalik2;

int main (){
	cin>>normal1>>normal2; 	//yey input
	for (int i=2; i>=0; i--){  //yey dibalik
		kebalik2+=normal1[i];
		kebalik1+=normal2[i];
	}
	if (kebalik1==normal1 && kebalik2==normal2){ //yey dicek
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
}