#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
typedef long long int ll;

int main(){
	int cnt[4]={};
	for(int i=0;i<6;i++){
		int t ;cin >> t;
		cnt[t-1]++;
	}
	if(cnt[0]*cnt[1]*cnt[2]*cnt[3]>0&&cnt[0]<3&&cnt[1]<3&&cnt[2]<3&&cnt[3]<3){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
}