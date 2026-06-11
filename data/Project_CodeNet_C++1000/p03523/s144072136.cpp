#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;cin>>s;
  if(s.size()>9){cout<<"NO"<<endl;return 0;}
  //-KIH-B-R-
  s=regex_replace(s,regex("HB"),"HAB");
  s=regex_replace(s,regex("BR"),"BAR");
  if(s.size()==7){
    string f="KIHABAR";
    for(int i=0;i<7;i++){
      if(s.at(i) !=f.at(i)){cout<<"NO"<<endl;return 0;}
    }
    cout<<"YES"<<endl;
  }else if(s.size()==8){
    string h="AKIHABAR";string d="KIHABARA";bool y=true;bool n=true;
    for(int i=0;i<8;i++){
      if(s.at(i) !=h.at(i)){y=false;}
    }
    for(int i=0;i<8;i++){
      if(s.at(i) !=d.at(i)){n=false;}
    }
    if((n)||(y)){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
  }else if(s.size()==9){
    string m="AKIHABARA";
    for(int i=0;i<9;i++){
      if(s.at(i) !=m.at(i)){cout<<"NO"<<endl;return 0;}
    }
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}