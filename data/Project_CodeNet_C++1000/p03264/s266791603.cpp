#include <iostream>
using namespace std;

//Compiler version g++ 6.3.0

int main()
{
    int k,num_pairs; 
    cin>> k;
    if(k%2==0){
    num_pairs =(k/2)*(k/2);
    }else{
    num_pairs =((k-1)/2)*(((k-1)/2)+1);
    }
    
    cout << num_pairs ;
    return 0; 
}