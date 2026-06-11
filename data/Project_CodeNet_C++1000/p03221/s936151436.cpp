#include<bits/stdc++.h>
using namespace std;
#define rep0(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
#define ll long long
#define test(a) cout << "*" << a << endl;
#define ss stringstream
int main (){
  int i,j;
  int N,M;
  int P[100001];
  int Y[100001];
  vector<ll>vec[100001];
  int X[100001][100001];
  
  cin >> N >> M;
  rep1(i,M){
    cin >> P[i] >> Y[i];
    vec[P[i]].push_back(Y[i]);
  }
  rep1(i,N){
    sort(vec[i].begin(),vec[i].end());
  }
  
  rep1(i,M){
    cout << setw(6) << setfill('0') << P[i] ;
    j = vec[P[i]].size()/2 ;
    if(Y[i] < vec[P[i]][ vec[P[i]].size()/2 ]){    
      while(1){
        if(vec[P[i]][j] == Y[i]){
          cout << setw(6) << setfill('0') << j+1 << endl;
          break;
        }
        j--; 
      }
    }   
    else{
      while(1){
        if(vec[P[i]][j] == Y[i]){
          cout << setw(6) << setfill('0') << j+1 << endl;
          break;
        }
        j++;
      }      
    } 
   
  }
 
}