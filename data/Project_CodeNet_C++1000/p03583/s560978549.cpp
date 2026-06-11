#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i=a; i<b; i++)
int mod = 1e9 + 7;
typedef long long ll;
 
int main(){
    long long N;
    cin >> N;

    for (long long h=1; h<=3500; h++){
        for (long long w=1; w<=3500; w++){
			long long n = (N * h * w) / ((4 * h - N) * w - N * h);
          	if(((4 * h - N) * w - N * h) > 0 && (N * h * w) % ((4 * h - N) * w - N * h)==0){
            	printf("%ld %ld %ld\n", h, w, n);
              	return 0;
            }
        }
    }
}   