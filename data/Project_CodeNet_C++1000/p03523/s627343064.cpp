#include<bits/stdc++.h>
using namespace std;

int main(){
  
  string s;
  cin>>s;
  
  if(s=="KIHBR"){
    cout<<"YES"<<endl;
  }
  else if(s=="AKIHBR" || s=="KIHABR" || s=="KIHBAR" || s=="KIHBRA"){
    cout<<"YES"<<endl;
  }
  else if(s=="AKIHABR" || s=="AKIHBAR" || s=="AKIHBRA" || s=="KIHABAR" || s=="KIHABRA" || s=="KIHBARA"){
    cout<<"YES"<<endl;
  }
  else if(s=="AKIHABR" || s=="AKIHABRA" || s=="AKIHBARA" || s=="KIBAHARA"){
    cout<<"YES"<<endl;
  }
  else if(s=="AKIHABARA"){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
  
}
