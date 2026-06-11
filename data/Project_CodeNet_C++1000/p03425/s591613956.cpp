#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	long long count = 0,N;
    string S;
  cin >> N;
  vector<long long> c(5,0);
  froop1(0,N){
    cin >> S;
   if(S[0] == 'M')c.at(0)++;
     else if(S[0] == 'A')c.at(1)++;
    else if(S[0] == 'R')c.at(2)++;
    else if(S[0] == 'C')c.at(3)++;
    else if(S[0] == 'H')c.at(4)++;
  }
  for(int i = 0;i < 5;i++){
    for(int j = i;j < 5;j++){
		for(int k = j;k < 5;k++){
         if(i != j && j != k && k != i){
           count += c.at(i) * c.at(j) * c.at(k);
        }
        }
    }
  }
  cout << count << endl;
return 0;
}