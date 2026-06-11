#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s; cin>>s; int n= s.size()/2;
    int x = 0,cnt=0;
    char c = s[n];
    if(s.size()%2!=0){
    while(s[n+x]==c&&s[n-x]==c){
        
        cnt++;
        x++;
        if(n+x>=s.size()) break;
        }
    }
    else
    while(s[n-x-1]==c&&s[n+x]==c){
        cnt++;
        x++;
        if(n+x>=s.size()) break;
    }
    cout<<cnt+n<<endl;
}
