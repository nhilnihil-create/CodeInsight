#include<iostream>
using namespace std;

int main(){
    int N,K;
    cin >>N>>K;
    if (N==1 && K==1)cout <<"YES";
    else{
    if(N%2==0){
        if((N/2)>=K) cout<<"YES";
        else cout <<"NO";
    }
    else {
      if(((N/2)+1)>=K) cout <<"YES";
      else cout <<"NO";
    }
    }
}