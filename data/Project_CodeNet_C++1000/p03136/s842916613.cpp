#include <bits/stdc++.h>
using namespace std;
int a[10004];
int main() {
int n;
cin>>n;
int mx=a[0];
int s=0;
for(int i=0;i<n;i++){
    cin>>a[i];
    if(mx<a[i])
        mx=a[i];
}
sort(a,a+n);
for(int i=0;i<n-1;i++){
    s+=a[i];
}
if(s>mx){
    cout<<"Yes"<<endl;
}
else{
    cout<<"No"<<endl;
}
  return 0;
}
