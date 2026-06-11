#include <iostream>
#include <string>
using namespace std;

int main()
{
   string s;
   cin>>s;
   if(s[0]!='A'){
    cout<<"WA";
    return 0;
   }
   else{
        int c=0,c2=0;
    for(int i=2;i<s.size()-1;i++){
        if(s[i]=='C'){
            c+=1;
        }
    }
    for(int i=0;i<s.size();i++){
        if(s[i]>=65&&s[i]<=90){
            c2+=1;
        }
    }
    if(c==1&&c2==2){
        cout<<"AC";
    }
    else{
        cout<<"WA";
    }

   }
    return 0;
}
