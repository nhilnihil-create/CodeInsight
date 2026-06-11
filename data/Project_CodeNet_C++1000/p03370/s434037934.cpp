#include <bits/stdc++.h>
using namespace std;
#include <math.h>
int main() {
 int N,X;
 cin>>N>>X;
 vector<int>m(N);
 int sum=0;
 for(int i=0;i<N;i++){
     cin>>m[i];
     sum+=m[i];
 }
 cout<<N+(X-sum)/ *min_element(m.begin(),m.end())<<endl;
 return 0;}