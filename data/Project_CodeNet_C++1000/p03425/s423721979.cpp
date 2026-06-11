#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	long long count = 0,N;
    string S;
  int I[10] = {0,0,0,0,0,0,1,1,1,2};
  int J[10] = {1,1,1,2,2,3,2,2,3,3};
  int K[10] = {2,3,4,3,4,4,3,4,4,4};
  cin >> N;
  vector<long long> c(5,0);
  froop1(0,N){
    cin >> S;
   if(S[0] == 'M')c.at(0)++;
     else if(S[0] == 'A')c.at(1)++;
    else if(S[0] == 'R')c.at(2)++;
    else if(S[0] == 'C')c.at(3)++;
    else if(S[0] == 'H') c.at(4)++;
  }
 froop1(0,10){
  count += c.at(I[i]) * c.at(J[i]) * c.at(K[i]); 
 }
  cout << count << endl;
return 0;
}