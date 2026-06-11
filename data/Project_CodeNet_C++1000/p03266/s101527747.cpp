#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    long long int n,k,a=0,b=0;
    cin>>n>>k;
    for(long long int i=1;i<n+1;i++){
        if(i%k==0){
            a++;
        }
        if((k%2==0&&i%k==k/2)){
            b++;
        }
    }
    cout<<a*a*a+b*b*b<<endl;
    return 0;
}
