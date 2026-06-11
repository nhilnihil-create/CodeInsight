#include <bits/stdc++.h>
using namespace std;
const int INF=999999999;
int main() {
 string S;
 cin>>S;
 bool ok =true;
 if(S[0]!='A'){ok=false;}
 int count1=0;
for(int i=2;i<S.size()-1;i++){
  if(S[i]=='C'){count1++;}
}
 if(count1!=1){ok=false;}
 int count2=0;
 for(int i=0;i<S.size();i++){
    if(S[i]>='A'&&S[i]<='Z'){count2++;}
 }
 if(count2!=2){ok=false;}

 if(ok){cout<<"AC"<<endl;}
 else{cout<<"WA"<<endl;}

 return 0;}