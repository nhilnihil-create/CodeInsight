
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int k;
	cin >> k;
	vector<ll> A(k);
	for(int i =0;i<k;i++)
	{cin >> A[i];}
	reverse(A.begin(),A.end());
	ll mn = 2;
	ll mx = 2;
	for(int i = 0;i<k;i++)
	{
		mn = mn%A[i]==0?mn:(mn/A[i]+1)*A[i];
		mx = (mx/A[i]+1)*A[i]-1;
		//cout<<mn<<endl;
	}
	if(mn<mx)
	cout<<mn<<' '<<mx<<endl;
	else
		cout<<-1<<endl;
	return 0;
}