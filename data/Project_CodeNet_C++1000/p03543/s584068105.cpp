#include <iostream>
using namespace std;
int main(void){
    // Your code here!
 char N[4];
scanf("%s",&N);
if(N[0] == N[1] && N[1] == N[2])
cout << "Yes" << endl;
else if(N[1] == N[2] && N[2] == N[3])
cout << "Yes" << endl;
else 
cout << "No" << endl;
 
 
 
}
