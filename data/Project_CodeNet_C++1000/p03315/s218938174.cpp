#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(a%b==0)
    return b;
    return gcd(b,a%b);
}
int lcm(int a,int b){
   return a*b/gcd(a,b);
}
int main(){
    int ans=0;
    string s;
    cin>>s;
    for(int i=0;i<4;i++){
        if(s.at(i)=='+')
        ans++;
        else
        ans--;
    }
    cout<<ans<<endl;
}