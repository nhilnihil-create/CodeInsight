#include<bits/stdc++.h>
using namespace std;
int main() {
    int N,A,B;
  	int cnt=0;
  	int sum=0;
    cin >> N >> A >> B;
    for(int i=0;i<=N;i++){
      int t=i;
      while(t>0){
        cnt=cnt+t%10;
        t=t/10;
      }
      if(A<=cnt&&cnt<=B){
        sum+=i;
      }
      cnt=0;
    }
    cout << sum << endl;
}
