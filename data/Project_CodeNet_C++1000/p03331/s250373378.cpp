#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, sumA=0, sumB=0, Min;
    cin >> N;
    for (int A=1; A<N; A++){
     		int B=N-A;
      		int a=A, b=B;
            sumA=0, sumB=0;
            while (true){
              		sumA += a%10;
                    a = (a-a%10)/10;
                    if (a==0) break;
            }
            while (true){
              		sumB += b%10;
                    b = (b-b%10)/10;
              		if (b==0) break;
            }
            if ((Min>sumA+sumB)||A==1){
              		Min = sumA+sumB;
            }
    }
    cout << Min << endl;
              		
}