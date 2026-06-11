#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N, T, A;
  	cin >> N >> T >> A;
  	int s[N];
  	int l =100000000, re;
  	for(int i = 0; i < N; i++){
    	cin >> s[i];
      	s[i] =fabs((T * 1000 - s[i] * 6) - A * 1000);
      	if(l > s[i]){
        l = s[i];
        re = i + 1;
        }
    }
  	cout << re << endl;
  	return 0;
}