#include<bits/stdc++.h>
using namespace std;
#define pi 2*acos(0.0)
int main(){
      string s;
      int d;
      cin>>s;
      cin>>d;
      if(d>s.size())cout<<endl;
      else{

        for(int i=0;i<s.size();i+=d){
            cout<<s[i];
        }
        cout<<endl;


      }
}
