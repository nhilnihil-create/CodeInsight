#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    string s;
    cin >> s;
  	int a=0,b=0;
    for(int i=0; i<s.size(); i++){
        if(i%2){
            if(s[i]=='0') a++;
            else b++;
        }
        else{
            if(s[i]=='1') a++;
            else b++;
        }
    }
    cout << min(a,b) << endl;
    return 0;
}
