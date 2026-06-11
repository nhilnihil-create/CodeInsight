#include <iostream>

using namespace std;

int main(){
    int A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;
    long int min=1000000000;
    long int value;
    if(X>=Y){
        for(int i=0;i<=2*X;i+=2){
            if(i/2>Y){
                value = C*i+(X-i/2)*A;
                if(value<min){
                    min = value;
                }
            }
            else{
                value = C*i+(X-i/2)*A+(Y-i/2)*B;
                if(value<min){
                    min = value;
                }
            }
        }
    }else{
        for(int i=0;i<=2*Y;i+=2){
            if(i/2>X){
                value = C*i+(Y-i/2)*B;
                if(value<min){
                    min = value;
                }
            }
            else{
                value = C*i+(X-i/2)*A+(Y-i/2)*B;
                if(value<min){
                    min = value;
                }
            }
        }
    }
    cout<<min<<endl;
}