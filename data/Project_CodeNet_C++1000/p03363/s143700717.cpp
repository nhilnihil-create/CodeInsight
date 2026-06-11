#include <bits/stdc++.h>
using namespace std;

int main() {
long long n;
cin >> n;
long long a[n];
long long ans = 0;
for(int i=0;i<n;i++){
    cin >> a[i];
}
long long sum[n+1];
sum[0]=0;
map<long long,long long> p;
p[0]=1;
for(long long i=0;i<n;i++){
    sum[i+1]=sum[i]+a[i];
}
for(long long i=0;i<n;i++){
  p[sum[i+1]]++;
}
for(auto i:p){
    ans+=(i.second*(i.second-1))/2;
}
cout << ans << endl;
}
