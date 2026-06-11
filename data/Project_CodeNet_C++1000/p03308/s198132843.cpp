#include<bits/stdc++.h>

using namespace std;
int main(){
    long n;
    cin >> n;
    long a[n],sum=0;
    for(int i=0; i<n; i++)
      cin >> a[i];
    for(int i=0; i<n; i++)
      sort(a,a+n);
    for(int i=0; i<n; i++){
      cout << a[n-1]-a[0] << endl;
      return 0;
    }
}