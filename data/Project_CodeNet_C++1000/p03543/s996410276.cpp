#include <bits/stdc++.h>
using namespace std;
int main(){
int N;
cin>>N;
if((N-N/1000*1000)%111==0){
    cout<<"Yes"<<endl;
}
else if((N-N%10)/10%111==0){
    cout<<"Yes"<<endl;
}
else
cout<<"No"<<endl;
}
