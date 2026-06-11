#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
using namespace std;
long long  INF=1000000000000000000;
long long mod=1000000007;
using namespace std;


int main(){
int  N,A,B;
cin>>N>>A>>B;
cout<<min(A,B)<<" "<<max(A+B-N,0)<<endl;
 return 0;
}
/*
10 3 5

3 0

10 7 5

5 2

100 100 100

100 100
*/