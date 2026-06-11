#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>

# define REP(i,n) for(int i=0; i<n; i++)

using namespace std;

int main(){
	int n;
	double input, ans1, ans2, mid, min;
	vector<double> a;
	
	scanf("%d", &n);
	
	REP(i,n){
		scanf("%lf", &input);
		a.push_back(input);
	}
	
	sort(a.begin(), a.end() );
	ans1 = a[n-1];
	
	mid = ans1/2;
	min = 1000000009;
	
	REP(i,n-1){
		//printf("|%lf - %lf| = %lf\n", mid, a[i], fabs(mid-a[i]));
		if (fabs(mid-a[i]) < min){
			min = fabs(mid-a[i]);
			ans2 = a[i];
		}
	}
	
	printf("%.0lf %.0lf\n", ans1, ans2);
	
	return 0;
	
}
