#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int INF = 1<<30;

int main(){
  int n, a, b;cin>>n>>a>>b;
  cout<<min(a, b)<<" "<<max(0, a+b-n)<<endl;
}