#include<iostream>
#include<string>
#include<locale>
using namespace std;
int main(){
    string S;
    int N,K;
    cin>>N>>K;
    cin>>S;
    S[K-1]=tolower(S[K-1]);
    cout<<S<<endl;
    return 0;
  

}
