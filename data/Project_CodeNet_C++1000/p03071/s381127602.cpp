#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

using namespace std;



int main()
{
	int A, B;
  	cin >> A >> B;
  	
  	int max[3];
  	max[0] = 2 * A - 1;
  	max[1] = A + B;
  	max[2] = 2 * B - 1; 
    
    sort(max, max + 3);
  	cout << max[2] << endl;
	
	
	return 0;
}