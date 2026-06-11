#include<bits/stdc++.h>
using namespace std;
int main(){ int n;
int p=1e5 ;
cin>>n;
int a[n];
for(int i=0 ;i<n ;i++){ int cnt=0 ;
cin>>a[i];

 while(a[i]%2==0){a[i]=a[i]/2; cnt++; }
p=min(p,cnt) ;
 }
cout<< p << endl;
return 0;
}


