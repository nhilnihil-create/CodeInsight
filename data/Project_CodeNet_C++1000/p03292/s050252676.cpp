#include<bits/stdc++.h>
using namespace std;
int main(){
int A1,A2,A3;
cin>>A1>>A2>>A3;
int mx=max(A1,max(A2,A3));
int mn=min(A1,min(A2,A3));
cout<<mx-mn;
return 0;
}
