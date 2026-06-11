#include <iostream>
#include <cmath>


using namespace std;
int main() {
  //  std::cout << "Hello, World!" << std::endl;
    long n,p,i,j,k,ans,max;
    cin>>n>>p;
    max=(long)pow(p,1.0/n)+1;
    for(i=max;i>0;i--){
        if(p%(long)pow(i,n)!=0)continue;
        ans=i;
        break;
    }
    cout << ans <<endl;
    return 0;
}