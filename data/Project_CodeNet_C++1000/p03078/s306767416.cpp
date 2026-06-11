#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

ll Record[3000];
int RecordCount = 0;

int Binary_Search(ll a, ll b[], int N, ll Value, bool isRecord){
	if(a + b[N-1] <= Value){
		return 0;
	}
	
	int min = 0;
	int max = N-1;
	while(max - min > 0){
		//printf("%lld %lld\n", min, max);
		int mid = min + (max - min)/2;
		if(a + b[mid] > Value){
			max = mid;
		}else{
			min = mid + 1;
		}
	}
	
	if(isRecord){
		for(int i = min; i < N; i++){
			Record[RecordCount] = a + b[i];
			RecordCount++;
		}
	}
	
	return N - min;
}

int main()
{
	int X, Y, Z, K;
	ll A[1000];
	ll B[1000];
	ll C[1000];
	
	scanf("%d %d %d %d", &X, &Y, &Z, &K);
	for(int i = 0; i < X; i++){
		scanf("%lld", &A[i]);
	}
	for(int i = 0; i < Y; i++){
		scanf("%lld", &B[i]);
	}
	for(int i = 0; i < Z; i++){
		scanf("%lld", &C[i]);
	}
	
	ll BC[1000000];
	
	for(int i = 0; i < Y; i++){
		for(int j = 0; j < Z; j++){
			BC[i*Z+j] = B[i] + C[j];
		}
	}
	
	sort(A, A+X);
	sort(BC, BC+Y*Z);
	
	{
		ll min = 0;
		ll max = 300000000000;
		
		while(max - min > 0){
			// printf("%lld %lld\n", min, max);
			ll mid = min + (max - min)/2;
			int count = 0;
			for(int j = 0; j < X; j++){
				count += Binary_Search(A[j], Y*Z > K ? BC + (Y*Z-K) : BC, Y*Z > K ? K : Y*Z, mid, false);
			}
			
			if(count < K){
				max = mid;
			}else{
				min = mid + 1;
			}
		}
		
		for(int j = 0; j < X; j++){
			Binary_Search(A[j], Y*Z > K ? BC + (Y*Z-K) : BC, Y*Z > K ? K : Y*Z, min, true);
		}
		sort(Record, Record + RecordCount);
		
		int count = 0;
		for(int i = RecordCount - 1; i >= 0; i--){
			printf("%lld\n", Record[i]);
			count ++;
		}
		
		for(int i = 0; i < K - count; i++){
			printf("%lld\n", min);
		}
	}
	
	return 0;
}