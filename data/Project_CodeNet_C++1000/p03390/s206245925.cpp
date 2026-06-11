
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define MOD 1000000007
#define rep(i,n) for(i=0;i<(n);i++)
#define loop(i,a,n) for(i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;

int main(void) {
  int i,j;
  int n;
  cin>>n;
  rep(i,n){
    ll A,B;
    cin>>A>>B;
    if(A > B) swap(A,B);
    /*
      1    …  A-1  (A)  A+1 … X
      A+B-1 … B+1  (B)  X-A … 1

      <- A-1人 ->      <- X-A人 ->

      縦の積がABを超えないようにしたときXを最大化する

      B > X-A かつ A < X
      A+B > X > A

     */

    // C^2 < AB となる最大のCを探す
    // A==B または A+1==BのときはC==Aとなるので場合分け
  
    if(A == B || A+1 == B){

      cout<<2*(A-1)<<endl;
      /*
	(A) A+1 … 2A-1
	(B) A-1 … 1 
       */

    }else{

      ll C = sqrt(A*B);
      if(C*C == A*B) C--;

      /*

	(A) A+1  …  C  C+1 …  2C
	(B) 2C-A  … C+1  C  …  1   

	    <-     2C-A人     ->

	C*(C+1) < AB ならばこれが最大
	そうでなければ
 
	(A) A+1  …  C  C+1 …  2C-1
        (B) 2C-A-1 … C C-1 …  1  

            <-    2C-A-1人     -> 
       */

      if((C+1)*C < A*B){

	cout << A-1 + 2*C-A  << endl; 

      }else{

	cout << A-1 + 2*C-A-1 << endl;

      }

    }

  }
}
