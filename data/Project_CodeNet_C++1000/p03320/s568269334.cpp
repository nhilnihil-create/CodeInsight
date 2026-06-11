#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
	long long k,cur=0;
	long long sn[10000],sn_s[10000];
	cin>>k;

	for (long long i=1; i<1000000; i++) {
		int i_s=0;
		for(long long j=i; j; j=j/10) {
			i_s+=j%10;
		}
		while(cur>0 && sn[cur-1]*i_s>i*sn_s[cur-1]) {
			cur--;
		}
		sn[cur]=i;
		sn_s[cur]=i_s;
		cur++;
	}
	int mm=10;
	for (int loop=7;loop<=15;loop++,mm=mm*10)
	for (long long i=100000; i<1000000; i++) {
		int i_s=0;
		long long x=(i+1)*mm-1;
		for(long long j=x; j; j=j/10) {
			i_s+=j%10;
		}
		while(cur>0 && sn[cur-1]*i_s>x*sn_s[cur-1]) {
			cur--;
		}
		sn[cur]=x;
		sn_s[cur]=i_s;
		cur++;
	}
	for (int i=0; i<k; i++) cout<<sn[i]<<endl;
	return 0;
}