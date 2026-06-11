#include <bits/stdc++.h>
using namespace std;
int main(){
bool a,b,c;
a=false;
b=false;
c=false;
string S;
cin>>S;
for(int i=0; i<3; i++){
    if(S.at(i)=='a'){
        a=true;
    }
    else if(S.at(i)=='b'){
        b=true;
    }
    else if(S.at(i)=='c'){
        c=true;
    }
}
if(a==true&&b==true&&c==true){
    cout<<"Yes"<<endl;
}
else
{
    cout<<"No"<<endl;
}

}
