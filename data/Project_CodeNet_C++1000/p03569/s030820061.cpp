#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
   string s;
   cin >> s;
   ll start = 0, end = s.length() - 1, x = 0;
   while(start < end){
        if(s[start] == s[end]){
            start++;
            end--;
        }
        else if(s[start] == 'x'){
            start++;
            x++;
        }
        else if(s[end] == 'x'){
            end--;
            x++;
        }else{
            cout << -1;
            return 0;
        }
   }
   cout << x;
   return 0;
}
