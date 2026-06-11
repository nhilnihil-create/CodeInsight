#include <bits/stdc++.h>
using namespace std;

int main(){
     int a,b,c,cnt=0;
     cin >> a >> b >> c;
    //bool can = false;
     for (int i =a;i <= b;i+=a){
         cnt++;
         //cout << i << endl;
         if(cnt==c) {
             //cnt == c;
             break;
         }

     }
     cout << cnt << endl;
}