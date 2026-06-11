#include <bits/stdc++.h>
using namespace std;
int main(){
	string a;
	int i,s=0x6ffffff;
    cin>>a;
    for(i=1;i<a.length();i++){
    if(a[i]!=a[i-1]){
    s=min(s,max(i,(int)a.length()-i));
    }}
    cout<<min(s,(int)a.length())<<endl;
    return 0;
}