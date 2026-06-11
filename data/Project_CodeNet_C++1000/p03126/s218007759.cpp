#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1001001001;

int a[12][12];

int main() {
 int N,M;
 cin>>N>>M;
 vector<int>count(M);
 for(int i=0;i<N;i++){
   int K;
   cin>>K;
   for(int j=0;j<K;j++){
     int A;
     cin>>A;
     A--;
     count[A]++;
   }
 }
 int count2=0;
 for(int i=0;i<M;i++){
   if(count[i]==N){count2++;}
 }
 cout<<count2<<endl;
  return 0;
}