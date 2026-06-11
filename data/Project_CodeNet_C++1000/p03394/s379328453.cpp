#include <iostream>
#include <vector>
#define llint long long

using namespace std;

llint n;
llint a[] = {2, 5, 63, 20};
vector<llint> vec[6], vec2;

int main(void)
{
	cin >> n;
	
	if(n <= 4){
		for(int i = 0; i < n; i++) cout << a[i] << " ";
		cout << endl;
		return 0;
	}
	
	for(int i = 1; i <= 30000; i++){
		if(i%2==0 || i%3==0) vec[i%6].push_back(i);
	}
	//for(int i = 0; i < 6; i++) cout << vec[i].size() << endl;
	for(int i = 0; i < 5000; i++){
		vec2.push_back(vec[2][i]);
		vec2.push_back(vec[4][i]);
	}
	for(int i = 0; i < 5000; i++){
		vec2.push_back(vec[3][i]);
	}
	vec2.insert(vec2.begin(), vec[3][4999]);
	vec2.insert(vec2.begin(), vec[3][4998]);
	vec2.pop_back();
	vec2.pop_back();
	
	if(n <= 15000){
		for(int i = 0; i < n/2*2; i++){
			cout << vec2[i] << " ";
		}
		if(n % 2) cout << vec[0][0];
		cout << endl;
		return 0;
	}
	for(int i = 0; i < vec2.size(); i++) cout << vec2[i] << " ";
	for(int i = 0; i < n-15000; i++) cout << vec[0][i] << " ";
	cout << endl;
	
	return 0;
}