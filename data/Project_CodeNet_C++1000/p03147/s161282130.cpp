#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int K;
	cin >> K;
	int flower[K+1];

	for(int i=0; i<K; i++)
		cin >> flower[i];

	flower[K]=0;

	int count=0;
	int chk=-1;

	while(count!=chk){
		chk=count;
		int l=0;
		int r=0;
		for(int i=0; i<K+1; i++){
			if(flower[i]>0) continue;
			if(flower[i]==0){
				r=i;
				if(l!=r){
					for(int j=l; j<r; j++)
						flower[j] = flower[j]-1;
					count++;
				}
				l=i+1;
			}
		}
	}
	cout << count << endl;
	return 0;
}