#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;


int main(){
string S;
cin >>S;
int lo = S.size();
string ans = "AC";

if(S[0]!='A')ans = "WA";
    int count = 0;
for(int i = 1; i < lo; i++){
if(isupper(S[i])){
if(i==1 || i==lo-1 || S[i]!='C') ans = "WA";
count++;
}






}
if(count!=1)ans="WA";

cout<<ans<<endl;

}
