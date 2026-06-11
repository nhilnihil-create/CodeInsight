#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;



int main() {

int N,cnt,ans=0;
cin>>N;

for (int n = 1; n <= N; ++ ++ n)
{
	cnt=0;
	for (int j = 1; j*j <=n; ++j)
	{
		if (n%j==0){cnt++;}
	}

if (cnt==4){ans++;}

}
   
   cout<<ans<<endl;
return 0;
}

