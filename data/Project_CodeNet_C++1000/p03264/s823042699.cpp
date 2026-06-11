#include<bits/stdc++.h>
using namespace std;
int k;
int main(){
cin>>k;
long long a=(k+2-1)/2;
if(k%2==0){
    cout<<(k/2)*(k/2)<<endl;
}
else{
    cout<<a*(k/2)<<endl;
}

return 0;
}
