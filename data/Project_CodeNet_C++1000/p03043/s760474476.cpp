#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n, k;
	double prob = 0;
	cin>> n>>k;
	if(n<k){
		for(int i=1;i<=n;i++){
			int l =k;
			int cnt = 0;
			int j=i;
			while(j<l){
				j *= 2;
				cnt++;
			}
			prob += pow(2, -cnt);
		}
	}else{
		prob += (n-k+1);
		for(int i=1; i<=k-1;i++){
			int l =k;
			int cnt = 0;
			int j=i;
			while(j<l){
				j *= 2;
				cnt++;
			}
			prob += pow(2, -cnt);
		}
	}
	prob /= n;
	printf("%.11lf\n", prob);
}