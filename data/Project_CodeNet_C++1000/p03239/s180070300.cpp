#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <locale>
using namespace std;
int main(){
	pair<int, int> NyT;
	pair<int, int> cyt;
	int costoMenor = 10001;
	cin>>NyT.first;
	cin>>NyT.second;
	for (int i = 0; i < NyT.first; i++)
	{
		cin>>cyt.first;
		cin>>cyt.second;
		if(cyt.second<=NyT.second){
			if(costoMenor > cyt.first){
				costoMenor = cyt.first;
			}
		}
	}
	if(costoMenor == 10001){
		cout<<"TLE";
	}else{
		cout<<costoMenor;
	}
	
	return 0;
}