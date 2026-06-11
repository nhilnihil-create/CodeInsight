#include <iostream>

using namespace std;

int main()
{
    int a,b,r;
    
    cin >> a >> b;
    
    //int area;
    //area = a*b/2;
    
    if((a*b*1)%2==0){
        r = 1;
    }else{
        r = 0;
    }
    
    if((a*b*2)%2==0){
        r=1;
    }else{
        r = 0;
    } 
    
    if((a*b*3)%2==0){
        r = 1;
    }else{
        r = 0;
    }
    
    
    if(r == 0){
        cout << "Yes";
    }else{
        cout << "No";
    }
    

    

    return 0;
}