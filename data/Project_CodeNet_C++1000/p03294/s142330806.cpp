#include <iostream>
using namespace std;

int modulo(int a[], int n)
{
 int sum=0;
  for(int i=0;i<n;i++)
    sum+=a[i]-1;
  return sum;
}
int main()
{
 int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
 int result = modulo(arr,n);
  cout<<result;
}