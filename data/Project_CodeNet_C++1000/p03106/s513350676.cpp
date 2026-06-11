
#include <bits/stdc++.h>
using namespace std;
#define rep0(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
   int a,b,n,count=0;cin>>a>>b>>n;
   int m=min(a,b);
   vector<int> v(b);
   rep1(i,m+1){
       if(a%i==0 && b%i==0){
           count++;
           v[count]=i;
       }
   }
   cout<<v[count-n+1]<<endl;
}