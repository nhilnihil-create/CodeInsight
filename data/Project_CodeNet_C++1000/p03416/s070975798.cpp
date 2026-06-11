#include<iostream>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    int c=0,x,y;
    for (int i=a;i<=b;i++){
        if(i%10==i/10000 && (i/10)%10==(i/1000)%10)
            
            c++;
    }
    cout << c << endl; 
}