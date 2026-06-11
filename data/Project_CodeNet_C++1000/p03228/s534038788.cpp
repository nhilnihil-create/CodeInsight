#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;

int main() {
 	 int64_t A,B,K;
    cin>>A>>B>>K;
    for(int i=0;i<K;i++){
      if(i%2==0){
        if(A%2!=0){A-=1;}
        A/=2;B+=A;
      }
      if(i%2!=0){
        if(B%2!=0){B-=1;}
        B/=2;A+=B;
      }
    }
    cout<<A<<" "<<B<<endl;
	return 0;
}