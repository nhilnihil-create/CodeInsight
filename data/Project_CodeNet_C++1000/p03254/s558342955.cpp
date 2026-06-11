#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main(){
  int N, x;
  cin >> N >> x;
  int a[N];
  for (int i=0;i<N;i++) cin >> a[i];
  sort(a, a+N);

  int retval = 0, sum = 0;
  for (int i=0;i<N;i++){
    sum += a[i];
    
    if(sum==x){
     retval = i+1;
     break;
    }
    else if (sum > x || i==N-1){
      retval = i;
      break;
    }
  }

  cout << retval << endl;
}