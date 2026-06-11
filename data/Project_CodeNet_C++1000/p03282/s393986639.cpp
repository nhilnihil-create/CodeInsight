#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,s,n) for(int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(){
   string s;
   ll k;
   cin >> s >> k;
   if(s[0]=='1'){
       if(k==1)
           cout << s[0] << endl;
        else{
            if(k<=100){
                bool flag = true;
                rep(i, k){
                    if(s[i]!='1'){
                        flag = false;
                        cout << s[i] << endl;
                        break;
                    }
                }
                if(flag)
                    cout << s[0] << endl;
            } else {
                bool flag = true;
                rep(i, 100) {
                    if(s[i]!='1'){
                        flag = false;
                        cout << s[i] << endl;
                        break;
                    }
                }
                if(flag)
                    cout << s[0] << endl;
            }
        }

   }else{
       cout<< s[0] << endl;
   }
   return 0;
}