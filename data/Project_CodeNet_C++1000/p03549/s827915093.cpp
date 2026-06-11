#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
 int n,m;
 cin >> n >> m;
 int sum=m*1900+(n-m)*100;
 int luck=pow(2,m);
 int ans=sum*luck;
 cout << ans << endl;
}

