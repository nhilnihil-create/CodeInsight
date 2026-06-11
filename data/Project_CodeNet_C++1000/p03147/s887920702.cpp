#define rep(i,n) for (int i=0;i<n;i++)
#include <vector>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
  int n,co=0,m=INT_MAX,max=0;
  cin >> n;
  vector <int> h(n);
  
  rep(i,n){
    cin >> h.at(i);
    if(m>h.at(i))
      m=h.at(i);
  }
  co+=m;
  rep(i,n){
    h.at(i)-=m;
    //cout << h.at(i) << endl;
    if(max<h.at(i))
      max=h.at(i);
  }
 // cout << max << endl;
  //cout << co <<endl;
  int i=0;

  
  
  
  rep(j,n){
    
    while(i<n){
      int s=i,f=s,m=INT_MAX;
    while(i<n && h.at(i)!=0){
      m=min(h.at(i),m);
      f=i;
      i++;
      
    }
    //f--;
    i++;
     // cout << "f=" << f << "s=" << s << "m="<< m << endl;
   if(m!=INT_MAX){   
     //cout << "f=" << f << "s=" << s << "m="<< m << endl;
    for(int k=f;k>=s;k--)
      h.at(k)-=m;
    co+=m;
   }
     
 //cout << co << endl;
      
    }
    i=0;
   /* rep(k,n)
     cout << h.at(k) << ' ' ;
   cout << endl;*/
    
  }
  cout << co << endl;
  
}