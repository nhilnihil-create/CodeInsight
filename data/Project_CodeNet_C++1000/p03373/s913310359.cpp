#include <bits/stdc++.h>

using namespace std;

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
int A,B,C,X,Y;
cin>>A>>B>>C>>X>>Y;

int mins = X>Y ? Y:X;
int maxs = X>Y ? X:Y;
int total=0;

if(A+B>C*2){
    total+=C*2*mins;
}
else{
    total+=A*mins;
    total+=B*mins;
}

int a=maxs-mins;
if(a*C*2>A*(X-mins)+B*(Y-mins)){
    total+=A*(X-mins);
    total+=B*(Y-mins);
}
else{
    total+=a*C*2;
}
cout<<total<<endl;

//system("pause");
return 0;
}