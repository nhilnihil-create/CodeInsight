#include<iostream>
using namespace std;
int main(void){
    int a,b,c = 0;
    cin >> a >> b >> c;
    if(b-a < 2 * c){
        for (size_t x = a; x <= b; x++)
        {
            cout << x << endl;
        }
        
    }else
    {
        for (int i = a; i < a+c; i++)
        {
            cout << i << endl;
        }
        for (int q = b-c+1; q <= b; q++)
        {
            cout << q << endl;
        }
    }
    
}