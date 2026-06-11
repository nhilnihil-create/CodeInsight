#include <bits/stdc++.h>
using namespace std;

int main() {
long long n,h,w;
cin >> n>>h>>w;
vector<long long>a(n);
vector<long long>b(n);
for(int i=0;i<n;i++){
    cin >> a.at(i)>>b.at(i);
}
long long ans=0;
for(int i=0;i<n;i++){
    if(a.at(i)>=h&&b.at(i)>=w){
        ans++;
    }
}
cout << ans << endl;
}
