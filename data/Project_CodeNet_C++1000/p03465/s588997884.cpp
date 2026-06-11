#include<bits/stdc++.h>
using namespace std;

bitset < 4000003 > arr; int N , sum;

int main(){
	cin >> N; arr[0] = 1;
	for(int x , i = 1 ; i <= N ; ++i){cin >> x; sum += x; arr = arr | (arr << x);}
	for(int i = (sum + 1) / 2 ; i <= sum ; ++i) if(arr[i]){cout << i; break;}
	return 0;
}