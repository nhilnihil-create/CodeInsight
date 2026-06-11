#include<iostream>
#include<math.h>
using namespace std;

int main(){
    long long a,b,d=0,e=0,y=0,z=0;
    string s;
    char c;
    cin>>a>>b>>s;
    b-=1;
    c=s[b];
    y = (int)(c);
    z=y+32;
    c = (char) (z);
    s[b]=c;
    cout<<s;
    return 0;
}
