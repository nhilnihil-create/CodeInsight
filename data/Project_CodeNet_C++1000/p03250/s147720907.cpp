#include<bits/stdc++.h>
using namespace std;
int main()
{
  	int x, y ,z;
 	cin >> x >> y >> z;
  	int a[] = {x , y , z};
  	sort(a , a + 3);
  	cout << a[2]*10 + a[1] + a[0] << endl;
 	return 0; 
}