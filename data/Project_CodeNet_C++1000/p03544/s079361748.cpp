#include <bits/stdc++.h>
#include <string.h>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define r0 return 0
#define INF (int)1e15

int const N = 1e5+1;
long long a[N];


int main(){

 long long n;
 cin>>n;

 a[0] = 2,a[1] = 1;

 for(int i=2;i<N;i++){

    a[i] = a[i-2] + a[i-1];

 }

  cout<<a[n]<<endl;

 return 0;
}
