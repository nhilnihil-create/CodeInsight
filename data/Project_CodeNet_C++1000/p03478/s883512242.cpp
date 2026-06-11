#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B, k, sum, Ans=0;
    cin >> N >> A >> B;
    for (int i=1; i<=N; i++){
        sum = 0;
        k = i;
        while (true){
          	  sum += k%10;
              if (k-(k%10)==0){
              	 break;
              }
              k = (k-(k%10))/10;
        }
        if ((A<=sum)&&(sum<=B)){
            Ans += i;
        }
    }
    cout << Ans << endl;
}