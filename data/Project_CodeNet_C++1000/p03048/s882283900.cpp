#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	int N,r,g,b,count;
  cin >> r >> g >> b >> N;
  froop1(0,N / r + 1){
    for(int j = 0;j < (N - i*r) / g + 1;j++){
        if((N - r*i - g*j) % b  == 0){
          count++;
        }
      }
    }
  cout << count << endl;

return 0;
}