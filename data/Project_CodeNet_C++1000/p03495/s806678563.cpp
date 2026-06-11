#include <bits/stdc++.h>
using namespace std;

int main(){
int n,k;
  cin >> n >> k;
int d[n];
  for(int i=0;i<n;i++) cin>>d[i];
int num[n]={0};
  for(int i=0;i<n;i++){
   if(d[i])num[d[i]-1]++;
  }
  sort(num,num+n,greater<int>());
int count=0;
for(int i=k;i<n;i++){
  if(num[i]>0)count+=num[i];
}
  
 cout << count << endl;
 return 0;


}