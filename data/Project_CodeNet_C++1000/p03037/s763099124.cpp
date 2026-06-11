#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)

//int max(int l, int a){
//    return l > a ?  l : a;
//}

using namespace std;
int main(){
   int n, m; cin >> n >> m;
   int l = 1, r = n;
   for(int i = 0; i < m; i++){
       int a, b; cin >> a >> b;
       l = max(l, a);
       r = min(r, b);
   }
   cout << max(r - l + 1, 0) << endl;

    return 0;
}
