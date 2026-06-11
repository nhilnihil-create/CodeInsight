#include <bits/stdc++.h>
#define inf 100000000
#define rep(i,n) for(int i=0;i<n;i++) 
using namespace std;
typedef long long ll;
int main (){
int n,m;
cin >> n >> m;
int x[m + 5];
rep(i,m){
    cin >> x[i];
}
sort(x, x + m);
int sub[m + 4];

rep(i,m-1){
    sub[i] = x[i + 1] - x[i];
}
sort(sub, sub + (m - 1));
ll sum = 0;
for (int i = 0; i < (m  - n);i++){
    sum += sub[i];
}
cout << sum << endl;
return 0;
}
