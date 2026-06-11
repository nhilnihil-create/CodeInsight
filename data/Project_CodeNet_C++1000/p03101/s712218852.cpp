#include<iostream>
using namespace std;
int main(){
	int h1,w1,h2,w2,result;
	cin>>h1>>w1>>h2>>w2;
	result=(h1*w1)-((h2*w1)+((h1-h2)*w2));
	cout<<result;
}