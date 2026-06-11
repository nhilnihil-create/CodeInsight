#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
int N,K;
cin>>N>>K;
int sum = 1;
for(int i = 0;i<N;i++){
if(sum<K){
sum+=sum;}
else{sum+=K;}
}
cout<<sum;
}