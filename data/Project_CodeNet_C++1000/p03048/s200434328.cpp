#include <iostream>
#include <functional>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int ans(int R,int G,int B,int N){
    int anse=0;
  	rep(i,N+1){
      rep(j,N+1){
        int v=N-R*i-G*j;
          if(v>=0 && v%B==0){
            anse++;
        }
        if(i*R+j*G>N)break;
      }
    if(i*R>N)break;
    }
    return anse;
}
 
 
int main() {
  int R,G,B,N;
	cin>>R>>G>>B>>N;
	cout<<ans(R,G,B,N)<<endl;
	return 0;
}