#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include<set> 
#include<math.h>
#define pai arccos(-1);
#define keta(n) cout << fixed << setprecision((n));
#define ll long long;
int main(){
  int n,calc=0;
  cin>>n;
  bool judge = false;
  for(int c=0;c<50;c++){
    for(int d=0;d<50;d++){
        if(n==4*c+7*d)
          judge = true;      
    }
  }
 	if(judge ==true)cout<<"Yes";
  else cout<<"No";

}
