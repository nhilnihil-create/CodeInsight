#include <iostream>
using namespace std;
int algae(int,int,int);
int x;
int main()
{
    int r,D,y;
    cin>>r;
    cin>>D;
    cin>>x;

    for(int i=0;i<10;i++) {
        x=algae(r,D,x);
        cout<<x<<"\n";
    }
    return 0;

}

int algae(int r,int d,int x) {
    int z;
    if(r>1 && r<6 && d>0 && d<101) {
        z=r*x-d;
        x=z;
    }
    return x;
}