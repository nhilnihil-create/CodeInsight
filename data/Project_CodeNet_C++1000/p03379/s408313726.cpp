
#include <bits/stdc++.h>
#include <string.h>
#include <vector>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define ll long long
#define pb push_back
//#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define r0 return 0
#define INF (int)1e15
#define MOD 1000000007
//#define N 12
#define sz 1000*1000

 int main(){

 int n; cin>>n;
 vector<int>v(n+10),y(n+10);

 for(int i=0;i<n;i++){
            cin>>v[i];
          y[i] = v[i];
 }


 sort(y.begin(),y.begin()+n); // used to sort only first n elements of the vector
  int mid = n/2;

  for(int i=0;i<n;i++){
      if(v[i] >= y[mid])
            cout<<y[mid-1]<<endl;
      else
            cout<<y[mid]<<endl;
  }

 return 0;
 }
