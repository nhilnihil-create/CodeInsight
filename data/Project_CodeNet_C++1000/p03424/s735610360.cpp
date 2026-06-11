#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
int N;
bool y=0;
string Color;
cin  >> N;
for(int i =0;i<N;i++){
cin >>Color;
if(Color=="Y"){
y=1;
break;
}}
if (y){
cout<<"Four";
}
else {
cout<<"Three";
}
}


