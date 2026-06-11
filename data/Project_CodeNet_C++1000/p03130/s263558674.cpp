#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;
 
int main() {
int a,b,c,d;
a=0;
b=0;
c=0;
d=0;

for(int i=0;i<6;i++){
int l;
cin>>l;
if(l==1)a++;
else if(l==2)b++;
else if(l==3)c++;
else d++;
}
string ans="NO";
if(a==1 && b==2&&c==2&&d==1)ans="YES";
cout<<ans<<endl;

}