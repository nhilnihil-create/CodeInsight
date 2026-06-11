#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a,b,c,k;
    cin>>a>>b>>c>>k;
    long long A=a-b;
    if(k%2==1){
      A=b-a;
    }
    cout<<A<<endl;
}
