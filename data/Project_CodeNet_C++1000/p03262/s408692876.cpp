#include <bits/stdc++.h>
using namespace std;
//最大公約数
long long GCD(long long a, long long b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(GCD(b, a%b));
   }
}
int main(){
  long long N,X;
  cin >> N >> X;
  if(N == 1){
    long long a;
    cin >> a;
    cout << abs(a-X) << endl;
    return 0;
  }
  vector<long long>vec(N+1);
  vec[N] = X;
  for(long long i=0; i<N; i++){
    cin >> vec[i];
  }
  sort(vec.begin(),vec.end());
  long long gccd = GCD(vec[2]-vec[1],vec[1]-vec[0]);
  for(long long i=0; i<N; i++){
    gccd = GCD(gccd,vec[i+1]-vec[i]);
  }
  cout << gccd << endl;
}
  
