#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    long long b=0,sum=0;
    int n=(int)s.size()-1;
    for(int i=n;i>=0;i--){
        if(s[i]=='B'){
            sum+=n;
            sum-=i;
            n--;
        }
    }
    cout<<sum<<endl;
}
