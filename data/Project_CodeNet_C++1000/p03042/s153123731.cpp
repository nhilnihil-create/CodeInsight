#include <iostream>
using namespace std;

int main() {
    int x;
    cin>>x;
    int f=x/100;
    int l=x%100;
    if(f>=1 && f<=12 && l>=1 && l<=12){
    	cout<<"AMBIGUOUS";
    } else if(f>=1 && f<=12){
    	cout<<"MMYY";
    } else if(l>=1 && l<=12){
    	cout<<"YYMM";
    } else{
    	cout<<"NA";
    }
	return 0;
}