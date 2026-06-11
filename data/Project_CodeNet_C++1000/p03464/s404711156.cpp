#include <iostream>
using namespace std;
int main(){
  long long n;cin>>n;
  long long a[n];
  for(int i = 0; n > i; i++)cin>>a[i];
  long long ansmn = 2;
  long long ansmx = 2;
  for(int i = n-1; 0 <= i; i--){
    long long tmp = ansmn/a[i]*a[i];
    while(ansmn > tmp)tmp+=a[i];
    ansmn = tmp;
    ansmx = ansmx/a[i]*a[i];
    ansmx+=a[i]-1;
    if(ansmn > ansmx){
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ansmn << " " << ansmx <<endl;

}