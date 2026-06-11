#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
int main(){
    int sum=700;
    string s;
    cin>>s;
    for(int n=0;n<3;n++){
        if(s[n]=='o')sum+=100;
    }
    cout<<sum;

    }
