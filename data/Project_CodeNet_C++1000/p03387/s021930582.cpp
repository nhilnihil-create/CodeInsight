#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;


int main(){
int A, B, C;
cin >>A>>B>>C;
if(A<B)swap(A,B);
if(A<C)swap(A,C);
int dif = (A-B)+(A-C);
int ans= dif/2;
if(dif%2==1)ans+=2;

cout<<ans<<endl;

}
