#include <bits/stdc++.h>
using namespace std;

int main() {
  string a;
  cin>>a;
  
  if(a=="AKIHABARA"||a=="AKIHABAR"||a=="AKIHABRA"||a=="AKIHABR"){
    cout<<"YES"<<endl;
  }
  else if(a=="AKIHBARA"||a=="AKIHBAR"||a=="AKIHBRA"||a=="AKIHBR"){
    cout<<"YES"<<endl;
  }
  else if(a=="KIHABARA"||a=="KIHABAR"||a=="KIHABRA"||a=="KIHABR"){
    cout<<"YES"<<endl;
  }
  else if(a=="KIHBARA"||a=="KIHBAR"||a=="KIHBRA"||a=="KIHBR"){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}