#include<bits/stdc++.h>
using namespace std;
int main() {
        int n;
	cin>>n;
        int a[n+1];
	for (int i=0; i<n;i++) {
		cin>>a[i];
         }
        int k=0;
        for (int i=0; i<n;i++) {
         while (a[i] % 2 == 0) {
                   a[i] /= 2;
                   k++;
            }
       }
	cout<<k<<"\n";
	
}
