#include <bits/stdc++.h> 
using namespace std; 
 
int main() 
{ 

    int r,D,x;
    cin>>r>>D>>x;

    int64_t x_next;
    for(int i=0;i<10;i++){
        x_next = r*x - D;
        cout<<x_next<<endl;
        x = x_next;
    }

    return 0; 
} 
