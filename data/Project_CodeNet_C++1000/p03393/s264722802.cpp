#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
  string s;
  cin >>s;
  int n=s.size();
  if(n==26){
     int chk=5000;
     for(int i=24;i>=0;i--){
       int a=s.at(i);
       int b=s.at(i+1);
       if(a<b){
         chk=i;
         break;
       }
     }
     if(chk==5000)cout <<-1 << endl;
     else{
       int m=26-chk;
       vector<char> l(m);
       rep(i,m){
         l.at(i)=s.at(chk+i);
       }
       sort(l.begin(),l.end());
       rep(i,chk){
         cout << s.at(i);
       }
       rep(i,m){
         if(l.at(i)==s.at(chk)){
       cout << l.at(i+1) << endl;
         }
       }
     }
  }
  else{
    set<char> l;
    rep(i,n){
      l.insert(s.at(i));
    }
    char ans;
    rep(i,26){
      int k='a'+i;
      if(l.count(char(k))){}
      else{
        ans=char(k);
        break;
      }
    }
    cout << s << ans << endl;
  }
}