#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()

ll N;
vector<vector<vector<double>>> note;
double dp(ll a,ll b,ll c) {
  if(a==0&&b==0&&c==0) {
return 0;
  }
  if(note[a][b][c]>=0) {
return note[a][b][c];
  }
  
 
  double s=0;
  double z=(N-a-b-c)/(double)N;
  z=1-z;
  s+=1/z;
  if(a>0) {
  s+=dp(a-1,b,c)*a/N/z;
  }
  if(b>0) {
  s+=dp(a+1,b-1,c)*b/N/z;
  }
  if(c>0) {
  s+=dp(a,b+1,c-1)*c/N/z;
  }
  
note[a][b][c]=s;
  
  return s;
}
  
  
  
  


 
int main() {
 
  cin>>N;
  note=vector<vector<vector<double>>> (N+1,vector<vector<double>>(N+1,vector<double>(N+1,-1)));
 vector<ll> vec(3,0);
  for(ll i=0;i<N;i++) {
ll A;
    cin>>A;
    if(A==1) {
vec[0]++;
    }
    else if(A==2) {
vec[1]++;
    }
    else {
vec[2]++;
    }
  }
 cout<<fixed<<setprecision(10);
 cout<<dp(vec[0],vec[1],vec[2])<<endl;

}
  
  
  
  
  
  
  
  
  
  
