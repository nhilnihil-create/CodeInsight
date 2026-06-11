#include <iostream>
#include <string>
using namespace std;
int main(void){
    string s;
    cin>>s;
    int counter=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='o') counter=counter+1;
    }
    printf("%d",700+100*counter);
    return 0;
    
}