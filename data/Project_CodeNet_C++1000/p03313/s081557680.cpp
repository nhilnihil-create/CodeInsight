#include<bits/stdc++.h>
using namespace std;
long long n;
long long A[1000000],dp1[1000000],dp2[1000000],S[1000000];
int main() {
	cin>>n;
	n=(long long)pow(2,n);
	for(int i=0;i<n;i++) {
      scanf("%lld",&A[i]);
      dp1[i] = 0;
      dp2[i] = 0;
    }
	for(int i=0;i<n;i++) {
      for(int j=i;j>0;j=(j-1)&i) {
        if (dp1[i] >= A[j]) {
          dp2[i] = max(dp2[i], A[j]);
        } else {
          dp2[i] = dp1[i];
          dp1[i] = A[j];
        }
      }
      if (dp1[i] >= A[0]) {
        dp2[i] = max(dp2[i], A[0]);
      } else {
        dp2[i] = dp1[i];
        dp1[i] = A[0];
      }
    }

    S[0] = dp1[0] + dp2[0];
	for(int i=1;i<n;i++) {
      S[i] = dp1[i] + dp2[i];
      S[i] = max(S[i-1], S[i]);
    }
	for(int i=1;i<n;i++)printf("%lld\n",S[i]);
	return 0;
} 