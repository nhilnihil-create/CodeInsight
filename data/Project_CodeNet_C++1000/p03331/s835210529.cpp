#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int min=n;
    for(int i=1;i<n;i++){

        int x,y;
        x=i%10+(i/10)%10+(i/100)%10+(i/1000)%10+(i/10000)%10+i/100000;
        y=(n-i)%10+((n-i)/10)%10+((n-i)/100)%10+((n-i)/1000)%10+((n-i)/10000)%10+(n-i)/100000;
        if(x+y<min) min=x+y;
    }
    cout<<min<<endl;
}
