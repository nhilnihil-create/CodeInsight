#include <bits/stdc++.h>
using namespace std;
/*
int  main() {
string s;
int n,q;
cin>>n>>q;
cin>>s;

int arr[n+1]={0};
int length=0;
for(int i=1;i<n;i++)
{
    if(s[i]=='C'&&s[i-1]=='A'){
     arr[i]=1; }

    arr[i]+=arr[i-1];
}


int l,r;
while(q--)
{
    cin>>l>>r;
    cout<<arr[r-1]-arr[l-1]<<endl;
}
return 0;
}
*/
 int main(){

 int n,Q;
 cin>>n>>Q;
  int a[n+1] = {0};
  string s;
  cin>>s;

  for(int i=1;i<s.length();i++){

     if(s[i] == 'C' && s[i-1] == 'A'){
        a[i] = 1; }

    a[i] += a[i-1];
  }


 while(Q--){
        int l,r;
  cin>>l>>r;
  cout<<a[r-1]-a[l-1]<<endl;
 }


 return 0;
 }

