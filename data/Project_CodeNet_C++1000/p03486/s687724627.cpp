#include <bits/stdc++.h>
 #define rep(i,n) for(int i=0;i<n;i++)
 using namespace std;
  int main(){
      string s,t;
      cin >> s >> t;
      sort(s.begin(),s.end());
      sort(t.begin(),t.end(),greater<>());
      int size=min(s.size(),t.size());

   rep(i,size){
       if(s[i]<t[i]){
           cout << "Yes" << endl;
         //  cout << " " << s << " " << t << endl;
           break;
       }
       if(s[i]>t[i]){
           cout << "No" << endl;
           break;
       }
           if(i+1==size && s.size()>t.size()){
               cout << "No" << endl;
           }
          if(i+1==size && s.size()<t.size()){
               cout << "Yes" << endl;
           }
         if(i+1==size && s.size()==t.size()){
               cout << "No" << endl;
           }
   }
   
    }