#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
int main()
{
    int n, ans=0;
    cin >> n;
    for(int i=105;i<=n;i+=2){
      int count=0;
      for(int j=1;j<=i;j++){
        if(i%j==0)count++;
        if(count >= 9)break;
      }
      if(count==8){
        ans++;
      }
    }
    cout << ans << endl;

    //--debug_end_stoper
    //string nanikayo; cin >> nanikayo;

    return 0;
}