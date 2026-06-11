#include <bits/stdc++.h>
using namespace std;

int64_t ret[101];
void prime_factor(int64_t N) {
  for(int64_t i = 2; i * i <= N; i++) {
    while(N % i == 0) {
      ret[i]++;
      N /= i;
    }
  }
  if(N != 1) ret[N]++;
}

int main(){
    int64_t n;
    cin >> n;
    int two=0;
    int four=0;
    int twofour=0;
    int onefour=0;
    int sevenfour=0;
    for(int64_t i=2;i<n+1;i++)prime_factor(i);
    for(int64_t i=2;i<=n;i++){
        if(ret[i]>=74)sevenfour++;
        if(ret[i]>=24)twofour++;
        if(ret[i]>=14)onefour++;
        if(ret[i]>=4)four++;
        if(ret[i]>=2)two++;
    }
    cout << sevenfour+twofour*(two-1)+onefour*(four-1)+four*(four-1)/2*(two-2) << endl;
}
