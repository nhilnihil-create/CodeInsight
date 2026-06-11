#include <iostream>
using namespace std;
int main() {


	int nofp,h,w,ans=0,arr[1002],arr1[1002];
	cin>>nofp>>h>>w;
	for(int i=1;i<=nofp;++i)
	{
		cin>>arr[i]>>arr1[i];

	}for(int j=1;j<=nofp;++j)
	{
		if(arr[j]>=h&&arr1[j]>=w)
			ans++;

	}cout<<ans<<endl;









    return 0;
}
