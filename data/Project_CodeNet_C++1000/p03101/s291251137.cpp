#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i< (int)(b); ++i)
using namespace std;


int main(){
   cin.tie(0);
   ios::sync_with_stdio(false);

   int h,h1,w,w1; cin >> h  >> w >> h1 >> w1;
   int ans=w*h- w*h1-h*w1+h1*w1;
   cout << ans << endl;

}

