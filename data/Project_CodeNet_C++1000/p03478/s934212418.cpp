#include<iostream>

using namespace std;

int sum = 0;
void check(int i,int a, int b)
{
	int j = i;
	int tmp = 0;
	while(i > 0){
		tmp += i % 10;
		i /= 10;
	}
	if(tmp >= a && tmp <= b)
		sum += j;

}
int main()
{
	int n,a,b;
	cin >> n >> a >> b;
	for(int i=1; i<=n; i++){
		check(i,a,b);
	}
	cout << sum << endl;

}