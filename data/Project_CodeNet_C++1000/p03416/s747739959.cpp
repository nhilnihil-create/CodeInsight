#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    int a,b;
    int ans=0;
    cin>>a>>b;
    for(int i=a; i<=b; i++){
        std::string s = std::to_string(i);
        if(s.at(0)==s.at(4) && s.at(1)==s.at(3)){
            ans++;
        }
    }
    cout<<ans<<endl;
}