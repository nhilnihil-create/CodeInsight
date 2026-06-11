#include <bits/stdc++.h>
#include <vector>


using namespace std;
int main(){

 string a,b;
cin>>a>>b;

sort(a.begin(),a.end());

sort(b.begin(),b.end(),greater<>());

if(a<b) cout<<"Yes"<<endl;
else 
cout<<"No"<<endl;

return 0;
}
