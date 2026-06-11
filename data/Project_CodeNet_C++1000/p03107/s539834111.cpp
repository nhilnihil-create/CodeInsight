#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int count=0;
    for(int i=0;i<(int)s.size()-1;i++){
      	if(i<0)continue;
        if(s.substr(i,2)=="01"||s.substr(i,2)=="10"){
            s.erase(s.begin()+i,s.begin()+i+2);
            count+=2;
          i-=2;
        }
    }
    cout<<count<<endl;
}