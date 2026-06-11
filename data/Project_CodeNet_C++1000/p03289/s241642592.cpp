#include <bits/stdc++.h>
#include <vector>
#include <math.h>

using namespace std;



int main(){

 string s; cin>>s;
  int n = s.length(),flag = 0;

  if(s[0] != 'A'){
    flag = 1;
    cout<<"WA"<<endl;
    return 0; }

    int cnt=0,pos=-1;
    for(int i=2;i<n-1;i++){
        if(s[i] == 'C'){
            cnt++;
            pos = i;}
    }

  if(cnt!=1 || pos == -1){
     flag = 1;
    cout<<"WA"<<endl;
    return 0;}


 for(int i=0;i<n;i++)
    if( (s[i] >= 'a' && s[i]<='z') && s[i] != 'C' && s[i]!= 'A')
     continue;
   else if(i != 0 && i!= pos){
        //cout<<i<<endl;
    cout<<"WA";
    return 0;}

  if(flag == 0)
  cout<<"AC"<<endl;


return 0;

}
