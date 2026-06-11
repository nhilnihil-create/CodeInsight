
#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i,n) for(int i=0;i< (n);++i)

using namespace std;

int main(){
    int K;
    cin>>K;
    int count=0;
    
    if(K%2==1){
       count= ((K+1)/2)*(K/2);
    }else{
        count=(K/2)*(K/2);
    }
    
        
    cout<<count<<endl;
    

}
