#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
int main() {
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  int ans = 0;
  for (int i = 0; i <= 3000; i++)
    for (int j = 0; j <= 3000; j++) {
      int v = i * R + j * G;
      if (N-v >=  && (N - v) % B == 0) ans++;
    }
  cout << ans << endl;
}
*/

int main(){

 int n,cnt=0,cnt1=0,cnt2=0,cnt3=0;
  cin>>n;

 while(n--){

  string das; cin>>das;

   for(int i=0;i<das.length();i++){
       if(das[i] == 'A' && das[i+1] == 'B')
        cnt++;
   }

   if(das[0] == 'B' && das[das.length()-1] == 'A')
    cnt1++;
   if( das[0] == 'B' && das[das.length()-1] != 'A')
    cnt2++;
   if(das[0] != 'B' && das[das.length()-1] == 'A')
     cnt3++;
 }

 if(cnt1 == 0 )
    cout<<cnt+cnt1+min(cnt2,cnt3)<<endl;
 else if(cnt1 != 0 && cnt2+cnt3 > 0)
    cout<<cnt+ cnt1 + min(cnt2,cnt3)<<endl;
 else if(cnt1 != 0 && cnt2+cnt3 == 0)
    cout<<cnt+cnt1-1<<endl;

return 0;
}
