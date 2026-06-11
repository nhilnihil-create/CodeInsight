#include <iostream>
using namespace std;
string s;
string ans = "";
void dfs(int i,int sum,string t){
      if(i == 3){
            if(sum == 7){
                  ans =  t + "=7";
            }
            return;
      }else{
            dfs(i + 1,sum + (s[i + 1] - '0'),t + "+" + s[i + 1]);
            dfs(i + 1,sum - (s[i + 1] - '0'),t + "-" + s[i + 1]);
      }
}
int main(void){
    cin >> s;
    dfs(0,s[0] - '0',s.substr(0,1));
    cout << ans << endl;
}
