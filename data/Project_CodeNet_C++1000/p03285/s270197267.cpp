#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1001001001;

int a[12][12];

int main() {
 int N;
 cin>>N;
 for(int i=0;i<100;i++){
   for(int j=0;j<100;j++){
     if(4*i+7*j==N){cout<<"Yes"<<endl;return 0;}
   }
 }
 cout<<"No"<<endl;
  return 0;
}