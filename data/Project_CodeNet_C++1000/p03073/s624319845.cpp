
#include <bits/stdc++.h>
#include <string.h>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define r0 return 0
#define INF (int)1e15


int main(){

 string s;
 cin>>s;

 int a=0,b=0;

 for(int i=0;i<s.length();i++){
    if(i%2 == 0){
        if(s[i] == '0')
            a++;
    }else {

       if(s[i] == '1')
        a++;

      }
 }

  for(int i=0;i<s.length();i++){
    if(i%2 == 0){
        if(s[i] == '1')
            b++;
    }else if(i%2 == 1){

      if(s[i] == '0')
        b++;
       }
 }

  cout<<min(a,b)<<endl;

return 0;
}