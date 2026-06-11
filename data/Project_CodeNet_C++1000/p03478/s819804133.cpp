#include <bits/stdc++.h>
using namespace std;

int main() {
	int N,A,B;
    cin >> N >> A >> B;
    int count = 0;
    for(int i=1;i<=N;i++){
      int a = i/10000;
      int b = i/1000-a*10;
      int c = i/100-a*100-b*10;
      int d = i/10-a*1000-b*100-c*10;
      int e = i%10;
      int sum = a+b+c+d+e;
      if(A<=sum && sum<=B){
        count = count+i;
      }
    }
    cout << count << endl;
}
