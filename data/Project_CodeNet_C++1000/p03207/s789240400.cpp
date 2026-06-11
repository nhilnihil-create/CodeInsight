#include <iostream>
#include <vector>
#include<string>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<int> p(N);
	
	for(int i = 0;i<N;i++){
		cin >> p[i];
	}
	int total = 0;
	int max = 0;
	for(int i = 0;i<N;i++){
		total += p[i];
		if(max<p[i]){
			max = p[i];
		}
	}
	
	total = total - max / 2;
	
	std::cout << total << endl; 	
	return 0;
}
