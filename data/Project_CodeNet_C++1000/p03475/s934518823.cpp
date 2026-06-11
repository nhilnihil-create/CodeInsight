#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;

struct tourist{
	int stationNo;
	int time;
};


int main()
{
	int n;
	cin>>n;
	int *c = new int[n-1];
	int *s = new int[n-1];
	int *f = new int[n-1];
	for(int i = 0; i < n-1; i++){
		cin>>c[i]>>s[i]>>f[i];
	}
	for(int i = 0; i <= n-1; i++){
		struct tourist t1;
		t1.stationNo = i;
		t1.time = 0;
		while(t1.stationNo != n-1){
			int index = t1.stationNo;
			if( t1.time < s[index]){
				t1.time = s[index] + c[index];
				t1.stationNo++;
			}else if( t1.time == s[index]){
				t1.time += c[index];
				t1.stationNo++;
			}else if( t1.time % f[index] == 0){
				t1.time += c[index];
				t1.stationNo++;
			}else{
				t1.time = t1.time - (t1.time % f[index]) + f[index] + c[index];
				t1.stationNo++;
			}
		}
		cout<<t1.time<<endl;
	};
	return 0;
}
