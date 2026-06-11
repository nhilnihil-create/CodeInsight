#include <bits/stdc++.h>
using namespace std;
 
 
 
int main() {
  string s;
  cin>>s;
  
  bool flag = false;
  //AKIHABARA
  if(s=="KIHBR"||s=="AKIHBR"||s=="KIHABR"||s=="KIHBAR"||s=="KIHBRA")
     flag=true;
  else if(s=="AKIHABR"||s=="AKIHBAR"||s=="AKIHBRA"||s=="KIHABAR"||s=="KIHABRA"||s=="KIHBARA")
     flag=true;
  else if(s=="AKIHABAR"||s=="AKIHABRA"||s=="AKIHBARA"||s=="KIHABAR"||s=="KIHBARA"||s=="KIHABRA")
     flag=true;
  else if(s=="AKIHABARA")
     flag=true;
     
     if(flag)
       cout<<"YES"<<endl;
     else
       cout<<"NO"<<endl;
     return 0;
}