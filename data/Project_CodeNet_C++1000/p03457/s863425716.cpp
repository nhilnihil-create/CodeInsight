#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

using namespace std;


int main()
{
	long N;
	cin >> N;
	
	long t[N + 1], x[N + 1], y[N + 1];
	t[0] = x[0] = y[0] = 0;
	for(long i = 1; i < N + 1; i++){
		cin >> t[i] >> x[i] >> y[i];
	}	
	
	bool root = true;
	for(long i = 0; i < N; i++){
		long dist = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
		long dt = t[i + 1] - t[i];
		if(dt < dist) root = false;
		else if(dt % 2 == 0){
			if(dist % 2 == 1) root = false;  
		}
		else if(dist % 2 == 0) root = false; 
	}
	
	if(root) cout << "Yes" << endl;
	else cout << "No" << endl; 
	
	return 0;
}