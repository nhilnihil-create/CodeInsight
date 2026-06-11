#include<iostream>
#include<string>
using namespace std;
// A placing marbles

//書かれてる整数が全て偶数である限り
//書かれている整数全てを2で割る

int N,sum,box[210];
//string s;
int main(){
	bool B=true;
	cin>>N;
	while(B==true){
		for(int i=0; i<N; i++){
			cin>>box[i];

			while (box[i]%2!=0){
				B=false;
				break;}
			while (box[i]%2==0){
				box[i] = box[i]/2;
				break;
			}	

		}
		if(B==true)sum++;
	}
	
cout<<sum<<endl;
}