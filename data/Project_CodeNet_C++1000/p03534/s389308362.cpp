#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int m,a,b,c,t;

int main(){
    string s;
    cin>>s;
    m=s.size();
    for(int i=0;i<m;i++){
        if(s[i]=='a') a++;
        else if(s[i]=='b') b++;
        else if(s[i]=='c') c++;
    }
    t=min(a,min(b,c));
    a-=t;b-=t;c-=t;
    if(a>=2||b>=2||c>=2) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

    return 0;
}
