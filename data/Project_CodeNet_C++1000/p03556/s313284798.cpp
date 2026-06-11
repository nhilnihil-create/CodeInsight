#include <iostream>
#include <string>
#include<math.h>
using namespace std;

int main()
{

 long long n;cin>>n;
    double x=sqrt(n);
    long long y=sqrt(n);
    if((x-y)==0)
    cout<<n<<endl;
    else {
        long long i=n;
        while(true){
            i--;
        double x=sqrt(i);
           long long y=sqrt(i);
            if((x-y)==0){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
