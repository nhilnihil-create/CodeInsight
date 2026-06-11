#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	if (n==3) {
		cout << 2 << ' ' << 5 << ' ' << 63 << endl;
	}
	else if (n==4) {
		cout << 2 << ' ' << 5 << ' ' << 20 << ' ' << 63 << endl;
	}
	else if (n==6) {
		cout << 2 << ' ' <<  4 << ' ' << 3 << ' ' << 9 << ' ' << 6 << ' ' << 12 << endl;
	}
	else if (n==5) {
		cout << 2 << ' ' << 4 << ' ' << 6 << ' ' << 3 << ' ' << 9 << endl;
  	}
	else {
		int t=6;
		if (n&1) {
			n--; cout << 6 << ' '; t=12;
		}
		cout << 2 << ' ' << 4 << ' ';
		cout << 3 << ' ' << 9 << ' ';
		n-=4;
		for (int i=5;i<=30000;i++) 
			if (i%2==0&&i%3!=0) 
			{
				cout << i << ' '; n--;
				if (!n) return 0;
			}
		for (int i=10;i<=30000;i++)
		 if (i%3==0&&i%2!=0) 
		 {
		 	cout << i << ' ' ; n--;
		 	if (!n) return 0;
		 }	
		for (int i=t;i<=30000;i++)
		if (i%6==0) {           
			cout << i << ' '; n--;
			if (!n) return 0;
		} 
	}
}