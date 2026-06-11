#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; ++i)

int main(){
    /*
    string a;
    int b = 0;
    cin >> a;
    for(int i =0; i<4; i++){
        if(a[i] == '+'){
            ++b;
        }else{
            --b;
        }
    }
    cout << b << endl;
    */
   string s; cin >> s;
   int sum=0;
   rep(i,4){
       if(s[i] == '+'){
           ++sum;
       }else{
           --sum;
       }
   }
   cout << sum << endl;
}