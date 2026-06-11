#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;


int main(){

int k;
cin >> k;
int ans,a=0,b=0;
for(int i = 1; i<=k;++i){
    
    if(i%2==1) b++;
    else a ++ ;
}
ans = a*b;
cout << ans << endl;


}