#include <iostream>

using namespace std;

int main()
{
    int n,a[201],i,chk=0,sum=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    while(chk!=1){
    for(i=0;i<n;i++){
        if(a[i]%2==0){
            a[i]=a[i]/2;
        }
        else if(a[i]%2!=0){
            chk=1;
            break;
        }
    }
    if(chk==0) sum+=1;
    }
    cout<<sum;
    return 0;
}
