#include<iostream>
#include<algorithm>
#include<vector>

#define req(i,n) for(i=0; i<(n); i++)
#define req2(i,k,n) for(i=(k); i<(n); i++)

using namespace std;

int main()
{
	int n,k,a,i;
	cin >> n >> k;
	vector<int> backet(n,0);
	
	req(i,n){
		cin >> a;
		backet[a-1]++;
	}

/*	
	req(i,n)
		cout << backet[i] << endl;
		cout << "sort" << endl;
*/
	sort(backet.rbegin(), backet.rend());

	int count = 0;
	req2(i,k,n)
		count += backet[i];
	
/*	
	req(i,n)
		cout << backet[i] << endl;
*/
	cout << count << endl;

}
