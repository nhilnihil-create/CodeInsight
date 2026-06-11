#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll=long long;

int main(){
 int n,count=0,a=0;
 cin >> n;
 vector<int> goal(n),len(n,0);
 rep(i,n) cin >> goal[i];

 while(a<n){
  if(len[a]==goal[a]) a++;
  if(len[a]<goal[a]){
   count++;
   for(int j=a; len[j]<goal[j]; j++) len[j] += 1;
  }
  
 }
 
  cout << count << endl;
}