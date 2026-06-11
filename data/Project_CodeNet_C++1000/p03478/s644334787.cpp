#include<iostream>
using namespace std;


int func(int ip){
	int temp=0;
	while(ip>0){
	temp += ip%10;
	ip =ip/10;
	}
	return temp;
}

int main(){
int N,A,B;
	int sum=0;
	cin>>N>>A>>B;
	for(int i = 0;i<=N;i++)
	{
		if(A<=func(i) && func(i)<=B)
		{
		sum +=i;
		}
	}

 cout<<sum<<endl;
}