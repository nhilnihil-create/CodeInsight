#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
  	cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++)
    {
    	cin >> A.at(i);
    }
  	sort(A.begin(),A.end());
    int sum=0;
  	for(int i=0; i<N; i++)
    {
    	if(i!=N-1) sum+=A.at(i);
      	else sum+=A.at(i)/2;
    }
  	cout << sum << endl;
}