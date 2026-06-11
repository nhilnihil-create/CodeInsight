#include<bits/stdc++.h>

using namespace std;

int main()
{
  string s;
  cin>>s;
  int len=s.length(),count=0,arr[11]={0},j=0;
  s[len]=' ';
  for(int i=0;i<=len;i++){
    if(s[i]=='A' || s[i]=='T' || s[i]=='G' || s[i]=='C'){
        count++;
    }
    else{
        arr[j++]=count;
        count=0;
    }
  }
   sort(arr,arr+11);
  cout<<arr[10];
  return 0;
}
