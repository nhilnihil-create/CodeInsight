#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N, max;
  	cin >> N;
  	int a[N];
  	max = 0;
  	for(int i = 0; i < N; i++){
    	cin >> a[i];
    }
  	for(int i = 0; i < N; i++){
    	for(int j = 0; j < N && i != j; j++){
          int s = fabs(a[i] - a[j]);
        	if(s > max){
            	max = s;
            }
        }
    }
  cout << max << endl;
  return 0;
}