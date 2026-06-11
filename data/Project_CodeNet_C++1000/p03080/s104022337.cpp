#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int N;
    cin>>N;
    string s;
    cin>>s;
    int count =0;
    for(int i = 0;i<N;i++){
        if(s.at(i)=='R'){
            count ++;
        }
    }
    if(count>N/2){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
        
}