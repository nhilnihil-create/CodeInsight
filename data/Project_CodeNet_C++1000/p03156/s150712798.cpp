
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;


int main(){
	/*input*/
	int n,a,b;
	cin >> n >> a >> b;
	vector<int> p(n,0);
	for(int i = 0; i < n; i++){
		cin >> p[i];
	}

	/*calc*/
	int ans = 0;
//	int	max = n/3;
	int small_cnt = 0;
	int middle_cnt = 0;
	int big_cnt = 0;
	for(int i = 0; i < n; i++){
		if(p[i] <=a) small_cnt++;
		if(p[i] > a && p[i] <= b) middle_cnt++;
		if(p[i] > b) big_cnt++;
	}
	ans = min(small_cnt,min(middle_cnt,big_cnt));

    /*output*/
	cout<< ans <<endl;
    return 0;
}
