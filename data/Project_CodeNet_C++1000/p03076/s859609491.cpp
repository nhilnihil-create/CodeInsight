#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  pii A[5];
  int a;
  rep(i,5) {
    cin >> a;
    A[i] = {(a+9)%10, a};
  }

  sort(A, A+5);
  int retval = 0;
  rep(i,5){
    if (i==0) retval += A[i].second;
    else retval += ((A[i].second+9)/10)*10;
  }

  cout << retval << endl;

  

  // cout << fixed << setprecision(6);
  return 0;
}
