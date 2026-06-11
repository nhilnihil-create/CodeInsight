#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int ans=700;
    if(s.at(0)=='o'){ans+=100;}
    if(s.at(1)=='o'){ans+=100;}
    if(s.at(2)=='o'){ans+=100;}
    cout<<ans<<endl;
    return 0;
}