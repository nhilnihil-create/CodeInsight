#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

int main()
{
  int N;
  cin >> N;
  int A[N];
  int min = INT_MAX;
  int flag = 0;
  for(int i=0;i<N;i++){
    cin >> A[i];
    if(A[i]<min){
      min = A[i];
    }
  }
  int result;
  sort(A,A+N);

  int tmp = 0;
  for(int i=0;i<N;i++){
    if(i==0){
      tmp = gcd(A[i],A[i+1]);
    }else if(i<N-1){
      tmp = gcd(tmp,A[i+1]);
    }
  }
  cout << tmp <<endl;
}