#include<iostream>
using namespace std;
#define sz 105

char f,g;
bool flag;
int arr[sz][sz],brr[sz],crr[sz];

int cal(int n){
    int x=0;

    for(int i=1; i<=n; i++){
        if(n%i==0)x++;
    }
    return x;

}


int main(){

    int n,m, i,j,k, x,y,z;

    cin>>n;
    x=0;
    for(i=1; i<=n; i+=2){
      if(cal(i)==8)x++;
    }
    cout<<x<<endl;



    return 0;

}