#include <bits/stdc++.h>
using namespace std;
 
int main() {

string S;
long long K;
cin >>S>>K;
long long count=1;
vector<int>vec(101,0);

for(int i=0;i<S.size();i++){
    if(S.at(i)=='1'){
        vec.at(i)++;
    }
    else{
        count=S.at(i)-'0';
        break;
    }
}
 if(K<=101){
    if(vec.at(K-1)==1){
        cout<<1<<endl;
    }
    else{
        cout<<count<<endl;
    }
 } 
 else{
         cout<<count<<endl; 
 } 
}