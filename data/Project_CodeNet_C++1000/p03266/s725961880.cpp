#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(void){
    // Your code here!
 ll i,k,n,s;
 s=0;
 cin >> n >> k;
 int a[k]={0};
 for(i=1;i<=n;i++)
 a[i%k]++;
 s=(ll)pow(a[0],3);
 if(k%2==0)
 s+=(ll)pow(a[k/2],3);
 cout << s;
 return 0;
}