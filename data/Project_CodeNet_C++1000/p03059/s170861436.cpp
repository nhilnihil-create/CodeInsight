#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

using namespace std;



int main()
{
	int A, B;
	double T;
	cin >> A >> B >> T;
	
	double time = 0;
	int biscuit = 0;
	while(time <= T + 0.5){
		time += A;
		biscuit += B;
		
	}
	
	cout << biscuit - B << endl;
	
	
	return 0;
}