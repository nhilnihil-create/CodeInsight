#include<bits/stdc++.h>
using namespace std;

string a,b;


int main(){
    cin>>a>>b;
    if(a[0]==b[2]&&a[1]==b[1]&&a[2]==b[0]){
      cout<<"YES";
    }
    else{
      cout<<"NO";
    }
}